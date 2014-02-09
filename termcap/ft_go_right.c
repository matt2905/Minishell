/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 11:04:53 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/07 17:59:32 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <termcap.h>
#include "minishell.h"

int		ft_go_right(t_data *d)
{
	if (d->line && d->line->next)
	{
		d->line = d->line->next;
		tputs(tgetstr("nd", NULL), 1, ft_int_putchar);
		if ((d->line->pos + d->len_prompt) % tgetnum("co") == 0)
		{
			tputs(tgetstr("cr", NULL), 1, ft_int_putchar);
			tputs(tgetstr("do", NULL), 1, ft_int_putchar);
		}
	}
	return (1);
}
