/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 15:25:18 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/09 22:02:50 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <termcap.h>
#include <unistd.h>
#include <libft.h>
#include "minishell.h"

static char		*ft_init(t_data *d, t_line **ptr, int flag)
{
	char	*tmp;

	if (flag == 0)
		d->history = d->history->next;
	else
		d->history = d->history->prev;
	tmp = d->history->line;
	while (d->line != d->first)
	{
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
		d->line = d->line->prev;
	}
	tputs(tgetstr("cd", NULL), 1, ft_int_putchar);
	ft_free_list(d->first);
	*ptr = ft_new_char(' ');
	ft_putstr(tmp);
	return (tmp);
}

int				ft_go_down(t_data *d)
{
	char	*tmp;
	int		i;
	t_line	*ptr;

	i = 0;
	if (d->history)
	{
		tmp = ft_init(d, &ptr, 0);
		while (tmp && tmp[i])
		{
			ft_add_char(&ptr, tmp[i]);
			if (ptr && ptr->next)
				ptr = ptr->next;
			i++;
		}
		d->line = ptr;
		d->first = ft_find_first(ptr);
		d->last = ft_find_last(ptr);
	}
	return (1);
}

int				ft_go_left(t_data *d)
{
	if (d->line != d->first)
	{
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
		d->line = d->line->prev;
	}
	return (1);
}

int				ft_go_right(t_data *d)
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

int				ft_go_up(t_data *d)
{
	char	*tmp;
	int		i;
	t_line	*ptr;

	i = 0;
	if (d->history)
	{
		tmp = ft_init(d, &ptr, 1);
		while (tmp && tmp[i])
		{
			ft_add_char(&ptr, tmp[i]);
			if (ptr && ptr->next)
				ptr = ptr->next;
			i++;
		}
		d->line = ptr;
		d->first = ft_find_first(ptr);
		d->last = ft_find_last(ptr);
	}
	return (1);
}
