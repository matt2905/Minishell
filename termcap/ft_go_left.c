/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 11:03:16 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/06 17:45:15 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <termcap.h>
#include "minishell.h"

int		ft_go_left(t_data *d)
{
	if (d->line != d->first)
	{
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
		d->line = d->line->prev;
	}
	return (1);
}
