/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:21:17 by alagroy-          #+#    #+#             */
/*   Updated: 2019/05/04 12:31:21 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_putc(int c)
{
	write(0, &c, 1);
	return (0);
}

void	tgetputstr(char *str)
{
	char	*cap;

	if (!(cap = tgetstr(str, NULL)))
		return ;
	else
		tputs(cap, 0, ft_putc);
}

int		main(int ac, char **av)
{
	t_select	*select;
	char		*clear;
	int			success;

	success = 0;
	if (ac == 1)
		return (1);
	if (!(select = ft_init_select(ac, av)))
		return (-1);
	tgetputstr("ti");
	if ((select->fd = check_input()) == -1)
		return (-1);
	g_select = select;
	init_signal();
	if ((clear = tgetstr("cl", NULL)))
		tputs(clear, 0, ft_putc);
	if (ft_core(select))
		success = 1;
	if (tcsetattr(0, 0, &(select->old_conf)) == -1)
		return (1);
	tgetputstr("te");
	if (success)
		ft_lstiter(select->args, ft_return);
	ft_putchar_fd('\n', 0);
	ft_lstdel(&select->args, &ft_delelem);
	return (0);
}
