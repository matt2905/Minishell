/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 15:27:05 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 21:02:01 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/ioctl.h>
#include <termcap.h>
#include "ft_termcap.h"

int				ft_alt_down(t_data *d)
{
	struct winsize	size;
	int				save;

	ioctl(0, TIOCGWINSZ, &size);
	save = d->line->pos + size.ws_col;
	if (d->line != d->last)
	{
		while (d->line != d->last && d->line->pos != save)
		{
			tputs(tgetstr("nd", NULL), 1, ft_int_putchar);
			d->line = d->line->next;
			if (ft_check_pos(d->line, d->len_prompt))
			{
				tputs(tgetstr("cr", NULL), 1, ft_int_putchar);
				tputs(tgetstr("do", NULL), 1, ft_int_putchar);
			}
		}
	}
	return (1);
}

int				ft_alt_left(t_data *d)
{
	if (d->line != d->first)
	{
		if (d->line != d->last)
		{
			while (d->line->c != ' ' && d->line->prev)
			{
				tputs(tgetstr("le", NULL), 1, ft_int_putchar);
				d->line = d->line->prev;
			}
		}
		while (d->line->c == ' ' && d->line->prev)
		{
			tputs(tgetstr("le", NULL), 1, ft_int_putchar);
			d->line = d->line->prev;
		}
		while (d->line->c != ' ' && d->line->prev)
		{
			tputs(tgetstr("le", NULL), 1, ft_int_putchar);
			d->line = d->line->prev;
		}
	}
	return (1);
}

static void		ft_ar_bis(t_data *d)
{
	while (d->line->c == ' ' && d->line->next)
	{
		tputs(tgetstr("nd", NULL), 1, ft_int_putchar);
		d->line = d->line->next;
		if (ft_check_pos(d->line, d->len_prompt))
		{
			tputs(tgetstr("cr", NULL), 1, ft_int_putchar);
			tputs(tgetstr("do", NULL), 1, ft_int_putchar);
		}
	}
	while (d->line->next && d->line->next->c != ' ')
	{
		tputs(tgetstr("nd", NULL), 1, ft_int_putchar);
		d->line = d->line->next;
		if (ft_check_pos(d->line, d->len_prompt))
		{
			tputs(tgetstr("cr", NULL), 1, ft_int_putchar);
			tputs(tgetstr("do", NULL), 1, ft_int_putchar);
		}
	}
}

int				ft_alt_right(t_data *d)
{
	if (d->line != d->last)
	{
		if (d->line != d->first)
		{
			while (d->line->c != ' ' && d->line->next)
			{
				tputs(tgetstr("nd", NULL), 1, ft_int_putchar);
				d->line = d->line->next;
				if (ft_check_pos(d->line, d->len_prompt))
				{
					tputs(tgetstr("cr", NULL), 1, ft_int_putchar);
					tputs(tgetstr("do", NULL), 1, ft_int_putchar);
				}
			}
		}
		ft_ar_bis(d);
	}
	return (1);
}

int				ft_alt_up(t_data *d)
{
	int				save;
	struct winsize	size;

	if (d->line != d->first)
	{
		ioctl(0, TIOCGWINSZ, &size);
		save = d->line->pos - size.ws_col;
		while (d->line != d->first && d->line->pos != save)
		{
			tputs(tgetstr("le", NULL), 1, ft_int_putchar);
			d->line = d->line->prev;
		}
	}
	return (1);
}
