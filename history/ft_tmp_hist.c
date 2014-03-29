/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmp_hist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 18:06:14 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 20:59:27 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_termcap.h"

static t_line	*ft_new_line(char *str)
{
	int		i;
	t_line	*tmp;
	t_line	*first;

	i = 0;
	tmp = ft_new_char(' ');
	first = tmp;
	while (str && str[i])
	{
		ft_add_char(&tmp, str[i]);
		tmp = tmp->next;
		i++;
	}
	tmp = first;
	return (tmp);
}

static t_tmp	*ft_save_line(t_tmp *next, t_line *line)
{
	t_tmp	*new;

	new = (t_tmp *)malloc(sizeof(*new));
	new->next = next;
	new->prev = NULL;
	new->line = ft_find_first(line);
	new->first = new->line;
	new->last = ft_find_last(new->first);
	return (new);
}

static t_tmp	*ft_new_tmp(t_data *d, t_line *line)
{
	t_tmp	*new;

	new = (t_tmp *)malloc(sizeof(*new));
	new->next = NULL;
	if (line)
		new->prev = ft_save_line(new, line);
	else
		new->prev = d->tmp_hist;
	new->line = ft_new_line(d->history->line);
	new->first = ft_find_first(new->line);
	new->last = ft_find_last(new->first);
	return (new);
}

void			ft_add_tmp(t_data *d)
{
	if (d->tmp_hist == NULL)
		d->tmp_hist = ft_new_tmp(d, d->line);
	else
	{
		d->tmp_hist->next = ft_new_tmp(d, NULL);
		d->tmp_hist = d->tmp_hist->next;
	}
}
