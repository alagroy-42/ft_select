/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:29:53 by alagroy-          #+#    #+#             */
/*   Updated: 2019/04/26 12:47:31 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_delelem(void *content, size_t size)
{
	(void)size;
	free(((t_elem *)content)->name);
	((t_elem *)content)->name = NULL;
	free(content);
	content = NULL;
}

void	ft_del(t_select *select)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = select->args;
	select->size_lst--;
	if (tmp && ((t_elem *)tmp->content)->on)
	{
		tmp->next ? ((t_elem *)tmp->next->content)->on = 1 : 0;
		select->args = tmp->next;
		ft_lstdelone(&tmp, &ft_delelem);
	}
	while (tmp && tmp->next)
	{
		if (((t_elem *)tmp->next->content)->on)
		{
			if (tmp->next->next)
				((t_elem *)tmp->next->next->content)->on = 1;
			else
				((t_elem *)select->args->content)->on = 1;
			tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			ft_lstdelone(&tmp2, &ft_delelem);
		}
		tmp = tmp->next;
	}
}

void	ft_move(t_select *select)
{
	t_list	*tmp;

	tmp = select->args;
	while (tmp)
	{
		if (((t_elem *)tmp->content)->on)
		{
			((t_elem *)tmp->content)->on = 0;
			if (tmp->next)
				((t_elem *)tmp->next->content)->on = 1;
			else if (select->args)
				((t_elem *)select->args->content)->on = 1;
			return ;
		}
		tmp = tmp->next;
	}
}

void	ft_set(t_select *select)
{
	t_list	*tmp;

	tmp = select->args;
	while (tmp)
	{
		if (((t_elem *)tmp->content)->on)
		{
			if (((t_elem *)tmp->content)->set)
				((t_elem *)tmp->content)->set = 0;
			else
				((t_elem *)tmp->content)->set = 1;
			((t_elem *)tmp->content)->on = 0;
			if (tmp->next)
				((t_elem *)tmp->next->content)->on = 1;
			else
				((t_elem *)select->args->content)->on = 1;
			return ;
		}
		tmp = tmp->next;
	}
}
