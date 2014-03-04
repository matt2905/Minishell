/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 10:57:13 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/04 10:18:03 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <unistd.h>
#include <libft.h>
#include "ft_termcap.h"

void		ft_print_new(t_data *d)
{
	int		pos;
	int		i;

	i = 0;
	pos = d->line->pos;
	ft_home(d);
	while (i < d->len_prompt)
	{
		write(0, "\b", 1);
		i++;
	}
	ft_prompt(d);
	while (d->line && d->line->next)
	{
		d->line = d->line->next;
		write(0, &d->line->c, 1);
	}
	while (d->line->pos != pos)
	{
		d->line = d->line->prev;
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
	}
}

int			ft_print(t_data *d)
{
	t_line	*tmp;
	int		i;

	if (ft_isprint(d->buff[0]))
	{
		i = 0;
		while (d->buff[i])
		{
			tmp = d->line;
			ft_add_char(&tmp, d->buff[i]);
			d->line = tmp;
			d->first = ft_find_first(tmp);
			d->last = ft_find_last(tmp);
			if (d->line->next != NULL)
				d->line = tmp->next;
			ft_print_new(d);
			i++;
		}
		return (1);
	}
	else
		return (0);
}
