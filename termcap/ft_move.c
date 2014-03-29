/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 15:25:18 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 21:06:35 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <termcap.h>
#include <libft.h>
#include "ft_termcap.h"
#include "ft_history.h"

static void		ft_print_hist(t_data *d)
{
	if (d->line && d->line->next && d->line->c == ' ')
		d->line = d->line->next;
	while (d->line && d->line->next)
	{
		ft_putchar_fd(d->line->c, 0);
		d->line = d->line->next;
	}
	if (d->line && d->line != d->first)
		ft_putchar_fd(d->line->c, 0);
}

int				ft_go_down(t_data *d)
{
	if (d->history && d->history->next->flag == 1)
	{
		ft_home(d);
		tputs(tgetstr("cd", NULL), 1, ft_int_putchar);
		d->tmp_hist = d->tmp_hist->prev;
		d->line = d->tmp_hist->line;
		d->first = d->tmp_hist->first;
		d->last = d->tmp_hist->last;
		ft_print_hist(d);
		d->history = d->history->next;
		d->history->flag = 0;
	}
	return (1);
}

int				ft_go_left(t_data *d)
{
	if (d->line != d->first)
	{
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
		d->line = d->line->prev;
	}
	return (1);
}

int				ft_go_right(t_data *d)
{
	if (d->line && d->line->next)
	{
		d->line = d->line->next;
		tputs(tgetstr("nd", NULL), 1, ft_int_putchar);
		if (ft_check_pos(d->line, d->len_prompt))
		{
			tputs(tgetstr("cr", NULL), 1, ft_int_putchar);
			tputs(tgetstr("do", NULL), 1, ft_int_putchar);
		}
	}
	return (1);
}

int				ft_go_up(t_data *d)
{
	if (d->history && d->history->flag == 0)
	{
		if (!d->tmp_hist || !d->tmp_hist->next)
			ft_add_tmp(d);
		else
			d->tmp_hist = d->tmp_hist->next;
		ft_home(d);
		tputs(tgetstr("cd", NULL), 1, ft_int_putchar);
		d->line = d->tmp_hist->line;
		d->first = d->tmp_hist->first;
		d->last = d->tmp_hist->last;
		ft_print_hist(d);
		d->history->flag = 1;
		d->history = d->history->prev;
	}
	return (1);
}
