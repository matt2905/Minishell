/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:19:25 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/08 13:36:25 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <unistd.h>
#include "libft.h"
#include "ft_termcap.h"

static void		ft_print_paste(t_line *line)
{
	int		save;
	int		len;

	save = line->index;
	len = line->len;
	ft_putstr_fd(line->str + line->index, 0);
	while (len > save)
	{
		len--;
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
	}
}

int				ft_paste(t_data *d)
{
	char	*tmp;

	if (d->cpy->str)
	{
		tputs(tgetstr("cd", NULL), 1, ft_int_putchar);
		tmp = ft_strnew(d->line->len + d->cpy->len + 1);
		if (d->line->str)
			ft_strncpy(tmp, d->line->str, d->line->index);
		ft_strcat(tmp, d->cpy->str);
		ft_putstr_fd(d->cpy->str, 0);
		d->line->index += d->cpy->len;
		if (d->line->str)
			ft_strcat(tmp, d->line->str + d->line->index);
		ft_strdel(&d->line->str);
		d->line->str = tmp;
		ft_print_paste(d->line);
		d->line->len += d->cpy->len;
	}
	return (1);
}
