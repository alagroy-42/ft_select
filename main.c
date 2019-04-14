/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:21:17 by alagroy-          #+#    #+#             */
/*   Updated: 2019/04/14 20:44:40 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_disp(t_list *elem)
{
	ft_putendl(elem->content);
}

int main(int ac, char **av)
{
	t_select	*select;

	if (ac == 1)
        return (-1);
	select = ft_init_select(ac, av);
	ft_lstiter(select->args, &ft_disp);
	return (0);
}