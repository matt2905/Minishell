/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 16:57:46 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/08 14:06:54 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_termcap.h"

void	ft_print_list(t_data *d)
{
	t_line	*tmp;

	tmp = d->line;
	tputs(tgetstr("cd", NULL), 1, ft_int_putchar);
	tputs(tgetstr("sc", NULL), 1, ft_int_putchar);
	if (tmp->str)
		ft_putstr_fd(tmp->str + tmp->index, 0);
	tputs(tgetstr("rc", NULL), 1, ft_int_putchar);
}

void	ft_free_list(t_line *list, int del)
{
	if (list)
	{
		ft_strdel(&list->str);
		list->len = 0;
		list->index = 0;
		if (del)
			free(list);
	}
}
