/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:21:17 by alagroy-          #+#    #+#             */
/*   Updated: 2019/04/25 13:24:47 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_putc(int c)
{
	write(0, &c, 1);
	return (0);
}

int		main(int ac, char **av)
{
	t_select	*select;
	char		*clear;

	if (ac == 1)
		return (1);
	if (!(select = ft_init_select(ac, av)))
		return (-1);
	if ((select->fd = check_input()) == -1)
		return (-1);
	g_select = select;
	signal(SIGWINCH, &resize);
	if ((clear = tgetstr("cl", NULL)))
		tputs(clear, 0, ft_putc);
	ft_core(select);
	if (tcsetattr(0, 0, &(select->old_conf)) == -1)
		return (1);
	ft_lstdel(&select->args, &ft_delelem);
	return (0);
}
