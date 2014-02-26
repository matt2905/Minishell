/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:19:25 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/26 18:46:02 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_termcap.h"

static void		ft_print_paste(t_data *d)
{
	while (d->line->next)
	{
		d->line = d->line->next;
		write(0, &d->line->c, 1);
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
		while (tmp)
		{
			if (line->next)
				line = line->next;
			ft_add_char(&line, tmp->c);
			tmp = tmp->next;
		}
		d->last = ft_find_last(d->first);
		ft_print_paste(d);
	}
	return (1);
}
