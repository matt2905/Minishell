/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 10:57:13 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/17 12:32:20 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <unistd.h>
#include <libft.h>
#include "ft_termcap.h"
#include "ft_minishell.h"

void		ft_print_new(t_data *d)
{
	int		pos;
	int		len;
	int		i;

	i = -1;
	pos = d->line->index;
	len = d->line->len;
	ft_home(d);
	while (++i < d->len_prompt)
		write(1, "\b", 1);
	ft_prompt(0);
	ft_putstr_fd(d->line->str, 0);
	while (len > pos)
	{
		len--;
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
	}
	d->line->index = pos;
}

void		ft_print_last(t_data *d)
{
	int		pos;
	int		len;

	pos = d->line->index;
	len = d->line->len;
	ft_putstr_fd(d->line->str + pos, 0);
	while (len > pos)
	{
		len--;
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
	}
}

int			ft_print(t_data *d)
{
	char	*tmp;

	if (d->buff[7])
		read(0, NULL, 16384);
	if (ft_isprint(d->buff[0]) && d->buff[1] == '\0')
	{
		tmp = ft_strnew(d->line->len + 2);
		if (d->line->str)
			ft_strncpy(tmp, d->line->str, d->line->index);
		ft_strcat(tmp, d->buff);
		if (d->line->str)
			ft_strcat(tmp, d->line->str + d->line->index);
		ft_strdel(&d->line->str);
		d->line->str = tmp;
		ft_print_new(d);
		d->line->index++;
		d->line->len++;
		return (1);
	}
	else
		return (0);
}
