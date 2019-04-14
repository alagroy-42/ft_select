/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:21:12 by alagroy-          #+#    #+#             */
/*   Updated: 2019/04/14 20:55:00 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include "ft_printf.h"
# include <termios.h>
# include <term.h>
# include <curses.h>

typedef struct termios  t_termios;

typedef struct          s_select
{
    t_termios	old_conf;
    t_termios	term;
    t_list		*args;
    char		*read;
    int			size_lst;
}                       t_select;


t_select	*ft_init_select(int ac, char **av);

#endif