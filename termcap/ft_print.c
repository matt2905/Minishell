/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 10:57:13 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 18:48:41 by mmartin          ###   ########.fr       */
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
	int		i;

	i = -1;
	pos = d->line->pos;
	ft_home(d);
	while (++i <= d->len_prompt)
		write(1, "\b", 1);
	ft_prompt(d);
	while (d->line && d->line->next)
	{
		d->line = d->line->next;
		write(0, &d->line->c, 1);
	}
	while (d->line->pos != pos)
	{
		d->line = d->line->prev;
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
	}
}

void		ft_print_last(t_data *d)
{
	int		pos;

	pos = d->line->pos;
	while (d->line && d->line->next)
	{
		write(0, &d->line->c, 1);
		d->line = d->line->next;
	}
	if (d->line)
		write(0, &d->line->c, 1);
	while (d->line->pos != pos)
	{
		d->line = d->line->prev;
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
	}
}

int			ft_print(t_data *d)
{
	t_line	*tmp;

	if (d->buff[7])
		read(0, NULL, 16384);
	if (ft_isprint(d->buff[0]) && d->buff[1] == '\0')
	{
		tmp = d->line;
		ft_add_char(&tmp, d->buff[0]);
		d->line = tmp;
		d->first = ft_find_first(tmp);
		d->last = ft_find_last(tmp);
		if (d->line->next != NULL)
			d->line = tmp->next;
		ft_print_new(d);
		return (1);
	}
	else
		return (0);
}
