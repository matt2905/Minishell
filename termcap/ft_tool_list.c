/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 16:57:46 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 21:10:20 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <stdlib.h>
#include <libft.h>
#include "ft_termcap.h"

void	ft_print_list(t_data *d)
{
	t_line	*tmp;

	tmp = d->line;
	tputs(tgetstr("cd", NULL), 1, ft_int_putchar);
	tputs(tgetstr("sc", NULL), 1, ft_int_putchar);
	if (tmp)
	{
		tmp = tmp->next;
		while (tmp)
		{
			ft_putchar_fd(tmp->c, 0);
			tmp = tmp->next;
		}
	}
	tputs(tgetstr("rc", NULL), 1, ft_int_putchar);
	d->last = ft_find_last(d->first);
}

void	ft_free_list(t_line *list)
{
	t_line	*tmp;
	t_line	*ptr;

	tmp = list;
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	while (tmp != NULL)
	{
		ptr = tmp;
		tmp = tmp->next;
		ptr->next = NULL;
		ptr->prev = NULL;
		ptr->c = '\0';
		free(ptr);
	}
}
