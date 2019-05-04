/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:26:56 by alagroy-          #+#    #+#             */
/*   Updated: 2019/05/04 12:35:42 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_signal(void)
{
	signal(SIGWINCH, &resize);
	signal(SIGINT, &ft_quit);
	signal(SIGCONT, &ft_cont);
}

void	resize(int sig)
{
	struct winsize	ws;

	if (sig == SIGWINCH)
	{
		ioctl(g_select->fd, TIOCGWINSZ, &ws);
		g_select->co = ws.ws_col;
		g_select->li = ws.ws_row;
		ft_display(g_select);
	}
}

void	ft_quit(int sig)
{
	if (sig != SIGINT)
		return ;
	ft_lstdel(&g_select->args, &ft_delelem);
	if (tcsetattr(0, 0, &g_select->old_conf) == -1)
		return ;
	exit(EXIT_FAILURE);
}

void	ft_cont(int sig)
{
	if (sig != SIGCONT)
		return ;
	if (tcsetattr(0, TCSADRAIN, &g_select->term) == -1)
		exit(EXIT_FAILURE);
	resize(SIGWINCH);
	ft_display(g_select);
}
