/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 13:30:13 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/08 13:41:54 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <termcap.h>
#include "ft_termcap.h"

int		ft_end(t_data *d)
{
	if (d->line->str)
	{
		while (d->line->index < d->line->len)
		{
			tputs(tgetstr("nd", NULL), 1, ft_int_putchar);
			d->line->index++;
			if (ft_check_pos(d->line, d->len_prompt))
			{
				tputs(tgetstr("cr", NULL), 1, ft_int_putchar);
				tputs(tgetstr("do", NULL), 1, ft_int_putchar);
			}
		}
	}
	return (1);
}
