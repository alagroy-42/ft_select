/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:21:12 by alagroy-          #+#    #+#             */
/*   Updated: 2019/04/24 16:26:25 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include "ft_printf.h"
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <signal.h>
# include <sys/ioctl.h>

typedef struct termios	t_termios;

typedef struct			s_elem
{
	char	*name;
	int		set;
	int		on;
}						t_elem;

typedef struct			s_select
{
	t_termios	old_conf;
	t_termios	term;
	t_list		*args;
	char		*read;
	int			size_lst;
	int			co;
	int			li;
}						t_select;

t_select				*g_select;

t_select				*ft_init_select(int ac, char **av);
void					ft_core(t_select *select);
int						ft_putc(int c);
void					resize(int sig);
void					ft_display(t_select *select);
void					ft_move(t_select *select);
void					ft_set(t_select *select);
void					ft_return(t_list *elem);
void					ft_del(t_select *select);
void					ft_delelem(void *elem, size_t size);

#endif
