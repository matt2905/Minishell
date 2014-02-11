/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 13:30:44 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/09 16:30:55 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termcap.h>
#include "minishell.h"

int		ft_home(t_data *d)
{
	if (d->line && d->first)
	{
		while (d->line != d->first)
		{
			tputs(tgetstr("le", NULL), 1, ft_int_putchar);
			d->line = d->line->prev;
		}
	}
	return (1);
}
