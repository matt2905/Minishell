/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 13:30:13 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/09 16:16:17 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termcap.h>
#include "minishell.h"

int		ft_end(t_data *d)
{
	if (d->line && d->last)
	{
		while (d->line != d->last)
		{
			tputs(tgetstr("nd", NULL), 1, ft_int_putchar);
			d->line = d->line->next;
			if ((d->line->pos + d->len_prompt) % tgetnum("co") == 0)
			{
				tputs(tgetstr("cr", NULL), 1, ft_int_putchar);
				tputs(tgetstr("do", NULL), 1, ft_int_putchar);
			}
		}
	}
	return (1);
}