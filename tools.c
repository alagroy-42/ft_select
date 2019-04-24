/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:40:33 by alagroy-          #+#    #+#             */
/*   Updated: 2019/04/24 16:09:26 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_return(t_list *elem)
{
	if (((t_elem *)elem->content)->set)
	{
		ft_putstr(((t_elem *)elem->content)->name);
		ft_putchar(' ');
	}
}

void			resize(int sig)
{
	struct winsize	ws;

	if (sig == SIGWINCH)
	{
		if (!(ioctl(0, TIOCGWINSZ, &ws)))
		{
			g_select->co = ws.ws_col;
			g_select->li = ws.ws_row;
			ft_display(g_select);
		}
	}
}

static t_list	*ft_make_argslst(int ac, char **av)
{
	t_list	*new;
	t_list	*begin;
	t_elem	*elem;
	int		i;

	i = 0;
	begin = NULL;
	while (++i < ac)
	{
		if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
			return (NULL);
		elem->name = ft_strdup(av[i]);
		elem->on = 0;
		elem->set = 0;
		new = ft_lstnew(elem, sizeof(t_elem));
		if (new && !begin)
			begin = new;
		else if (new)
			ft_lstend(&begin, new);
	}
	return (begin);
}

t_select		*ft_init_select(int ac, char **av)
{
	t_select	*select;
	char		*name_term;

	if (!(select = (t_select *)malloc(sizeof(t_select))))
		return (NULL);
	if (!(name_term = getenv("TERM")))
		return (NULL);
	if (tgetent(NULL, name_term) != 1)
		return (NULL);
	tcgetattr(0, &(select->term));
	tcgetattr(0, &(select->old_conf));
	select->term.c_lflag &= ~(ICANON);
	select->term.c_lflag &= ~(ECHO);
	select->term.c_cc[VMIN] = 1;
	select->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &select->term) == -1)
		return (NULL);
	select->size_lst = ac;
	select->args = ft_make_argslst(ac, av);
	select->read = NULL;
	select->co = tgetnum("co");
	select->li = tgetnum("li");
	((t_elem *)select->args->content)->on = 1;
	return (select);
}
