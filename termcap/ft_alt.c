/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 15:27:05 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/08 11:26:07 by mmartin          ###   ########.fr       */
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
	save = d->line->index + size.ws_col;
	if (d->line->index < d->line->len)
	{
		while (d->line->index < d->line->len && d->line->index < save)
		{
			tputs(tgetstr("nd", NULL), 1, ft_int_putchar);
			d->line->index++;
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
	if (d->line->index > 0)
	{
		if (d->line->index < d->line->len)
		{
			while (d->line->str[d->line->index] != ' ' && d->line->index > 0)
			{
				tputs(tgetstr("le", NULL), 1, ft_int_putchar);
				d->line->index--;
			}
		}
		while (d->line->str[d->line->index] == ' ' && d->line->index > 0)
		{
			tputs(tgetstr("le", NULL), 1, ft_int_putchar);
			d->line->index--;
		}
		while (d->line->str[d->line->index] != ' ' && d->line->index > 0)
		{
			tputs(tgetstr("le", NULL), 1, ft_int_putchar);
			d->line->index--;;
		}
	}
	return (1);
}

static void		ft_ar_bis(t_data *d, int len)
{
	while (d->line->str[d->line->index] == ' ' && d->line->index < len)
	{
		tputs(tgetstr("nd", NULL), 1, ft_int_putchar);
		d->line->index++;
		if (ft_check_pos(d->line, d->len_prompt))
		{
			tputs(tgetstr("cr", NULL), 1, ft_int_putchar);
			tputs(tgetstr("do", NULL), 1, ft_int_putchar);
		}
	}
	while (d->line->index < len && d->line->str[d->line->index + 1] != ' ')
	{
		tputs(tgetstr("nd", NULL), 1, ft_int_putchar);
		d->line->index++;
		if (ft_check_pos(d->line, d->len_prompt))
		{
			tputs(tgetstr("cr", NULL), 1, ft_int_putchar);
			tputs(tgetstr("do", NULL), 1, ft_int_putchar);
		}
	}
}

int				ft_alt_right(t_data *d)
{
	int		len;

	len = d->line->len;
	if (d->line->index < len)
	{
		if (d->line->index > 0)
		{
			while (d->line->str[d->line->index] != ' ' && d->line->index < len)
			{
				tputs(tgetstr("nd", NULL), 1, ft_int_putchar);
				d->line->index++;
				if (ft_check_pos(d->line, d->len_prompt))
				{
					tputs(tgetstr("cr", NULL), 1, ft_int_putchar);
					tputs(tgetstr("do", NULL), 1, ft_int_putchar);
				}
			}
		}
		ft_ar_bis(d, len);
	}
	return (1);
}

int				ft_alt_up(t_data *d)
{
	int				save;
	struct winsize	size;

	if (d->line->index > 0)
	{
		ioctl(0, TIOCGWINSZ, &size);
		save = d->line->index - size.ws_col;
		while (d->line->index > 0 && d->line->index > save)
		{
			tputs(tgetstr("le", NULL), 1, ft_int_putchar);
			d->line->index--;
		}
	}
	return (1);
}
