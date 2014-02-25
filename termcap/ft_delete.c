/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 11:06:42 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/25 16:58:34 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <termcap.h>
#include "ft_termcap.h"

int		ft_delete(t_data *d)
{
	t_line	*ptr;

	tputs(tgetstr("dm", NULL), 1, ft_int_putchar);
	tputs(tgetstr("dc", NULL), 1, ft_int_putchar);
	tputs(tgetstr("ed", NULL), 1, ft_int_putchar);
	if (d->line)
	{
		if (d->line->next)
		{
			ptr = d->line->next;
			if (d->line->next->next)
				d->line->next->next->prev = d->line->next->prev;
			d->line->next = d->line->next->next;
			free(ptr);
		}
	}
	ft_print_list(d);
	return (1);
}
