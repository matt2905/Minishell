/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:19:25 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/01 10:30:28 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <unistd.h>
#include "ft_termcap.h"

static void		ft_print_paste(t_line *line)
{
	int		save;

	save = line->pos;
	while (line && line->next)
	{
		line = line->next;
		write(0, &line->c, 1);
	}
	while (line->pos != save)
	{
		line = line->prev;
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
	}
}

int				ft_paste(t_data *d)
{
	t_line	*tmp;
	t_line	*line;

	if (d->cpy)
	{
		line = d->line;
		tmp = d->cpy;
		tputs(tgetstr("cd", NULL), 1, ft_int_putchar);
		while (tmp)
		{
			write(1, &tmp->c, 1);
			ft_add_char(&line, tmp->c);
			if (line->next)
				line = line->next;
			tmp = tmp->next;
		}
		d->line = line;
		d->first = ft_find_first(d->line);
		d->last = ft_find_last(d->first);
		ft_print_paste(line);
	}
	return (1);
}
