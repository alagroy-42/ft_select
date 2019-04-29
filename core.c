/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:56:19 by alagroy-          #+#    #+#             */
/*   Updated: 2019/04/29 12:10:26 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static char	*find_color(t_list *elem)
{
	if (((t_elem *)elem->content)->set && ((t_elem *)elem->content)->on)
		return ("\033[30;47;4m");
	else if (((t_elem *)elem->content)->on)
		return ("\033[4m");
	else if (((t_elem *)elem->content)->set)
		return ("\033[30;47m");
	else
		return ("\033[0;0m");
}

void		ft_display(t_select *select)
{
	t_list	*tmp;
	char	*cl;
	int		i;

	tmp = select->args;
	if ((cl = tgetstr("cl", NULL)))
		tputs(cl, 0, ft_putc);
	i = 0;
	if (select->li - 1 < select->size_lst)
		return (ft_display_col(select));
	while (tmp)
	{
		if ((cl = tgetstr("cm", NULL)))
			tputs(tgoto(cl, 0, i), 0, ft_putc);
		ft_dprintf(0, "%s%s\033[0;0m\n", find_color(tmp),
				((t_elem *)tmp->content)->name);
		i++;
		tmp = tmp->next;
	}
}

void		ft_core(t_select *select)
{
	char	buf[4];
	int		ret;

	ft_display(select);
	while (select->size_lst && (ret = read(0, buf, 3)) && ret != -1)
	{
		buf[ret] = '\0';
		if (buf[0] == '\n')
			return (ft_lstiter(select->args, &ft_return));
		else if (buf[0] == '\t')
			ft_move(select);
		else if (buf[0] == ' ')
			ft_set(select);
		else if (buf[0] == 27 && ret == 1)
			return ;
		else if (buf[0] == 126 || buf[0] == 127)
			ft_del(select);
		ft_display(select);
	}
}
