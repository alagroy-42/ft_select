/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:21:12 by alagroy-          #+#    #+#             */
/*   Updated: 2019/04/29 13:42:48 by alagroy-         ###   ########.fr       */
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
# include <fcntl.h>

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
	int			bigger_word;
	int			co;
	int			li;
	int			fd;
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
int						check_input(void);
void					find_max_len(t_select *select);
void					ft_display_col(t_select *select);
void					ft_lstmapindex(t_select *args);

#endif
