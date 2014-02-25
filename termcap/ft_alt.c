/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 15:27:05 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/25 16:58:10 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <termcap.h>
#include "ft_termcap.h"

int		ft_alt_down(t_data *d)
{
	int		save;

	save = d->line->pos + tgetnum("co");
	if (d->line != d->last)
	{
		while (d->line != d->last && d->line->pos != save)
		{
			tputs(tgetstr("nd", NULL), 1, ft_int_putchar);
			d->line = d->line->next;
			if ((d->line->pos + d->len_prompt) % tgetnum("co") == 0)
			{
				tputs(tgetstr("cr", NULL), 1, ft_int_putchar);
				tputs(tgetstr("do", NULL), 1, ft_int_putchar);
			}
		}
	}
	return (1);
}

int		ft_alt_left(t_data *d)
{
	if (d->line != d->first)
	{
		while (d->line->c != ' ' && d->line->prev)
		{
			tputs(tgetstr("le", NULL), 1, ft_int_putchar);
			d->line = d->line->prev;
		}
		while (d->line->c == ' ' && d->line->prev)
		{
			tputs(tgetstr("le", NULL), 1, ft_int_putchar);
			d->line = d->line->prev;
		}
	}
		return (1);
}

int		ft_alt_right(t_data *d)
{
	if (d->line != d->last)
	{
		while (d->line->c == ' ' && d->line->next)
		{
			tputs(tgetstr("nd", NULL), 1, ft_int_putchar);
			d->line = d->line->next;
			if ((d->line->pos + d->len_prompt) % tgetnum("co") == 0)
			{
				tputs(tgetstr("cr", NULL), 1, ft_int_putchar);
				tputs(tgetstr("do", NULL), 1, ft_int_putchar);
			}
		}
		while (d->line->c != ' ' && d->line->next)
		{
			tputs(tgetstr("nd", NULL), 1, ft_int_putchar);
			d->line = d->line->next;
			if ((d->line->pos + d->len_prompt) % tgetnum("co") == 0)
			{
				tputs(tgetstr("cr", NULL), 1, ft_int_putchar);
				tputs(tgetstr("do", NULL), 1, ft_int_putchar);
			}
		}
	}
	return (1);
}

int		ft_alt_up(t_data *d)
{
	int		save;

	if (d->line != d->first)
	{
		if (d->line == d->last)
			save = d->line->prev->pos - tgetnum("co") + 1;
		else
			save = d->line->pos - tgetnum("co");
		while (d->line != d->first && d->line->pos != save)
		{
			tputs(tgetstr("le", NULL), 1, ft_int_putchar);
			d->line = d->line->prev;
		}
	}
	return (1);
}
