/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:19:06 by alagroy-          #+#    #+#             */
/*   Updated: 2019/05/04 12:53:16 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_display_col(t_select *select)
{
	char	*cm;
	t_list	*tmp;

	if (select->li - 1 && select->co < ((select->bigger_word + 6)
				* (select->size_lst / (select->li - 1))
				+ (select->bigger_word)))
	{
		ft_dprintf(0, "ERROR: Resize the window please !");
		return ;
	}
	if (!(cm = tgetstr("cm", NULL)))
		return ;
	tmp = select->args;
	while (tmp)
	{
		tputs(tgoto(cm, (tmp->content_size / (select->li - 1))
					* (select->bigger_word + 6), tmp->content_size
					% (select->li - 1)), 0, ft_putc);
		ft_dprintf(0, "%s%s\033[0;0m\n", find_color(tmp),
				((t_elem *)tmp->content)->name);
		tmp = tmp->next;
	}
	tputs(tgoto(cm, 0, select->li), 0, ft_putc);
}
