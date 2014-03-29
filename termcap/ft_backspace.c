/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 11:08:24 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 21:02:16 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termcap.h>
#include "ft_termcap.h"

int		ft_backspace(t_data *d)
{
	t_line	*ptr;

	if (d->line && d->first && d->line != d->first)
	{
		if (d->line->next)
			d->line->next->prev = d->line->prev;
		if (d->line->prev)
		{
			ptr = d->line;
			d->line->prev->next = d->line->next;
			d->line = d->line->prev;
			free(ptr);
			tputs(tgetstr("le", NULL), 1, ft_int_putchar);
			tputs(tgetstr("dm", NULL), 1, ft_int_putchar);
			tputs(tgetstr("dc", NULL), 1, ft_int_putchar);
			tputs(tgetstr("ed", NULL), 1, ft_int_putchar);
		}
	}
	ft_print_list(d);
	return (1);
}
