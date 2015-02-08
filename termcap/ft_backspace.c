/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 11:08:24 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/08 13:20:29 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termcap.h>
#include "libft.h"
#include "ft_termcap.h"

int		ft_backspace(t_data *d)
{
	char	*tmp;

	if (d->line && d->line->index > 0)
	{
		tmp = ft_strnew(d->line->len);
		ft_strncpy(tmp, d->line->str, d->line->index - 1);
		ft_strcat(tmp, d->line->str + d->line->index);
		ft_strdel(&d->line->str);
		d->line->str = tmp;
		d->line->index--;
		d->line->len--;
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
		tputs(tgetstr("dm", NULL), 1, ft_int_putchar);
		tputs(tgetstr("dc", NULL), 1, ft_int_putchar);
		tputs(tgetstr("ed", NULL), 1, ft_int_putchar);
	}
	ft_print_list(d);
	return (1);
}
