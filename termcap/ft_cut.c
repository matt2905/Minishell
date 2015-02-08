/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:19:03 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/08 13:31:15 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <termcap.h>
#include "libft.h"
#include "ft_termcap.h"

static void		ft_copy(t_line **new, t_line *line)
{
	char	*tmp;

	tmp = ft_strsub(line->str, line->index, line->len - line->index);
	ft_strdel(&(*new)->str);
	(*new)->str = tmp;
	(*new)->index = 0;
	(*new)->len = ft_strlen(tmp);
}

int				ft_cut(t_data *d)
{
	char	*tmp;

	if (d->line->index < d->line->len)
	{
		ft_copy(&d->cpy, d->line);
		tputs(tgetstr("cd", NULL), 1, ft_int_putchar);
		tmp = ft_strndup(d->line->str, d->line->index);
		ft_strdel(&d->line->str);
		d->line->str = tmp;
	}
	return (1);
}
