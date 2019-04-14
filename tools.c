/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:40:33 by alagroy-          #+#    #+#             */
/*   Updated: 2019/04/14 20:55:25 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_list	*ft_make_argslst(int ac, char **av)
{
    t_list  *new;
    t_list  *begin;
    int     i;

    i = 0;
    begin = NULL;
    while (++i < ac)
    {
        new = ft_lstnew(ft_strdup(av[i]), sizeof(char *));
        if (new && !begin)
            begin = new;
        else if (new)
            ft_lstend(&begin, new);
    }
	return (begin);
}

t_select	*ft_init_select(int ac, char **av)
{
	t_select	*select;
	char		*name_term;

	if (!(select = (t_select *)malloc(sizeof(t_select))))
		return (NULL);
	if (!(name_term = getenv("TERM")))
		return (NULL);
	if (tgetent(NULL, name_term) != 1)
		return (NULL);
	tcgetattr(0, &(select->term));
	tcgetattr(0, &(select->old_conf));
	select->size_lst = ac;
	select->args = ft_make_argslst(ac, av);
	select->read = NULL;
	return (select);
}