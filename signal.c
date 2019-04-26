/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:26:56 by alagroy-          #+#    #+#             */
/*   Updated: 2019/04/26 15:45:00 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
