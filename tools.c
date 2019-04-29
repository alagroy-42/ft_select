/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:40:33 by alagroy-          #+#    #+#             */
/*   Updated: 2019/04/29 13:42:27 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			find_max_len(t_select *select)
{
	t_list	*tmp;
	int		len;

	tmp = select->args;
	select->bigger_word = 0;
	while (tmp)
	{
		len = ft_strlen(((t_elem *)tmp->content)->name);
		if (len > select->bigger_word)
			select->bigger_word = len;
		tmp = tmp->next;
	}
}

int				check_input(void)
{
	int		fd;

	if (!isatty(0))
		return (-1);
	if ((fd = open(ttyname(0), O_RDWR)) == -1)
		return (-1);
	return (fd);
}

void			ft_return(t_list *elem)
{
	if (((t_elem *)elem->content)->set)
	{
		ft_putstr(((t_elem *)elem->content)->name);
		ft_putchar(' ');
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
		free(elem);
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
	select->size_lst = ac - 1;
	select->args = ft_make_argslst(ac, av);
	select->read = NULL;
	select->co = tgetnum("co");
	select->li = tgetnum("li");
	((t_elem *)select->args->content)->on = 1;
	find_max_len(select);
	ft_lstmapindex(select);
	return (select);
}
