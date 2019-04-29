/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:19:06 by alagroy-          #+#    #+#             */
/*   Updated: 2019/04/29 12:15:49 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_display_col(t_select *select)
{
	if (select->co < (select->bigger_word + 6) * (select->size_lst / select->li
				+ 1))
	{
		ft_dprintf(0, "ERROR: Resize the window please !");
		return ;
	}
}
