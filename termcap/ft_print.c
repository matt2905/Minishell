/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 10:57:13 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/06 17:39:54 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <unistd.h>
#include <libft.h>
#include "minishell.h"

int		ft_print(t_data *d)
{
	t_line	*tmp;

	if (ft_isprint(d->buff[0]) && d->buff[1] == '\0')
	{
		tmp = d->line;
		ft_add_char(&tmp, d->buff[0]);
		d->line = tmp;
		d->first = ft_find_first(tmp);
		d->last = ft_find_last(tmp);
		tputs(tgetstr("im", NULL), 1, ft_int_putchar);
		write(0, d->buff, 1);
		tputs(tgetstr("ei", NULL), 1, ft_int_putchar);
		if (d->line->next != NULL)
			d->line = tmp->next;
		return (1);
	}
	else
		return (0);
}
