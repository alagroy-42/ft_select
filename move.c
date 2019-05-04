/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:26:37 by alagroy-          #+#    #+#             */
/*   Updated: 2019/05/04 12:12:00 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_get_index_on(t_select *select)
{
	t_list	*tmp;

	tmp = select->args;
	while (tmp)
	{
		if (((t_elem *)tmp->content)->on)
			return (tmp->content_size);
		tmp = tmp->next;
	}
	return (0);
}

static void	ft_bl(void)
{
	char	*bl;

	if ((bl = tgetstr("bl", NULL)))
		tputs(bl, 0, ft_putc);
}

static void	ft_select_nthelem(t_select *select, int index)
{
	t_list	*tmp;

	tmp = select->args;
	while (tmp)
	{
		if (((t_elem *)tmp->content)->on)
			((t_elem *)tmp->content)->on = 0;
		tmp = tmp->next;
	}
	tmp = select->args;
	while (tmp)
	{
		if ((int)tmp->content_size == index)
			((t_elem *)tmp->content)->on = 1;
		tmp = tmp->next;
	}
}

void		ft_arrow(t_select *select, char key)
{
	int	index;

	index = ft_get_index_on(select);
	if (key == 'A')
		index > 0 ? ft_select_nthelem(select, index - 1)
			: ft_select_nthelem(select, select->size_lst - 1);
	else if (key == 'B')
		index + 1 < select->size_lst ? ft_select_nthelem(select, index + 1)
			: ft_select_nthelem(select, 0);
	else if (key == 'C')
		index + select->li - 1 < select->size_lst ? ft_select_nthelem(select,
				index + select->li - 1) : ft_bl();
	else if (key == 'D')
		index - select->li + 1 >= 0 ? ft_select_nthelem(select, index - select->li 
				+ 1) : ft_bl();
}
