/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 13:30:44 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/08 11:54:57 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <termcap.h>
#include "ft_termcap.h"

int		ft_home(t_data *d)
{
	if (d->line)
	{
		while (d->line->index > 0)
		{
			tputs(tgetstr("le", NULL), 1, ft_int_putchar);
			d->line->index--;
		}
	}
	return (1);
}
