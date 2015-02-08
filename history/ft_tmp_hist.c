/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmp_hist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 18:06:14 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/08 13:04:35 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_termcap.h"

static t_line	*ft_new_line(char *str)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(*line));
	line->index = ft_strlen(str);
	line->len = line->index;
	line->str = ft_strdup(str);
	return (line);
}

static t_tmp	*ft_save_line(t_tmp *next, t_line *line)
{
	t_tmp	*new;

	new = (t_tmp *)malloc(sizeof(*new));
	new->next = next;
	new->prev = NULL;
	new->line = line;
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
