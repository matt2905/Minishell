/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:19:03 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/26 16:40:12 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <termcap.h>
#include "ft_termcap.h"

static void		ft_copy(t_line **new, t_line *line)
{
	t_line	*tmp;

	tmp = line;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		ft_add_char(new, tmp->c);
		if ((*new)->next)
			*new = (*new)->next;
	}
	while (*new && (*new)->prev)
		*new = (*new)->prev;

}

int				ft_cut(t_data *d)
{
	t_line	*tmp;

	if (d->cpy)
	{
		ft_free_list(d->cpy);
		d->cpy = NULL;
	}
	tmp = d->cpy;
	ft_copy(&tmp, d->line);
	d->cpy = tmp;
	tputs(tgetstr("cd", NULL), 1, ft_int_putchar);
	tmp = d->line->next;
	d->line->next = NULL;
	d->last = d->line;
	tmp->prev = NULL;
	ft_free_list(tmp);
	return (1);
}