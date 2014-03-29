/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_hist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 16:33:36 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 20:58:50 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_termcap.h"

static void		ft_free_tmp(t_tmp **save, t_data *d)
{
	t_tmp	*ptr;

	if (*save != d->tmp_hist)
	{
		ptr = *save;
		*save = (*save)->next;
		ft_free_list(ptr->line);
		ptr->first = NULL;
		ptr->last = NULL;
		ptr->next = NULL;
		ptr->prev = NULL;
		free(ptr);
	}
	else
	{
		ptr = *save;
		*save = (*save)->next;
		ptr->next = NULL;
		ptr->prev = NULL;
		free(ptr);
	}
}

void			ft_reset_history(t_data *d)
{
	t_history	*tmp;
	t_tmp		*save;

	if (d->last_hist)
	{
		tmp = d->last_hist;
		tmp->flag = 0;
		tmp = tmp->next;
		while (tmp != d->last_hist)
		{
			tmp->flag = 0;
			tmp = tmp->next;
		}
		d->history = d->first_hist;
		save = d->tmp_hist;
		while (save && save->prev)
			save = save->prev;
		while (save)
			ft_free_tmp(&save, d);
		d->tmp_hist = NULL;
	}
}
