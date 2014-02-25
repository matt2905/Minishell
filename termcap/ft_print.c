/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 10:57:13 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/25 16:59:21 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <unistd.h>
#include <libft.h>
#include "ft_termcap.h"

void		ft_print_new(t_line *tmp)
{
	int		save;

	save = tmp->pos;
	tputs(tgetstr("cd", NULL), 1, ft_int_putchar);
	while (tmp->next)
	{
		tmp = tmp->next;
		write(0, &tmp->c, 1);
	}
	while (tmp->prev->pos != save)
	{
		tmp = tmp->prev;
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
	}
}

int			ft_print(t_data *d)
{
	t_line	*tmp;

	if (ft_isprint(d->buff[0]) && d->buff[1] == '\0')
	{
		tmp = d->line;
		ft_add_char(&tmp, d->buff[0]);
		d->line = tmp;
		d->first = ft_find_first(tmp);
		d->last = ft_find_last(tmp);
		if (d->line->next != NULL)
			d->line = tmp->next;
		ft_print_new(tmp);
		return (1);
	}
	else
		return (0);
}
