/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 11:06:42 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/08 11:54:02 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <termcap.h>
#include "libft.h"
#include "ft_termcap.h"

int		ft_delete(t_data *d)
{
	char	*tmp;

	tputs(tgetstr("dm", NULL), 1, ft_int_putchar);
	tputs(tgetstr("dc", NULL), 1, ft_int_putchar);
	tputs(tgetstr("ed", NULL), 1, ft_int_putchar);
	if (d->line)
	{
		if (d->line->index < d->line->len)
		{
			tmp = ft_strnew(d->line->len);
			ft_strncpy(tmp, d->line->str, d->line->index);
			ft_strcpy(tmp + d->line->index, d->line->str + d->line->index + 1);
			ft_strdel(&d->line->str);
			d->line->str = tmp;
		}
	}
	ft_print_list(d);
	return (1);
}
