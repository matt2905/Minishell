/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 11:05:56 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/26 11:59:22 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "ft_termcap.h"

static void		ft_print_error(t_line *first)
{
	t_line	*tmp;

	tmp = first;
	while (tmp)
	{
		ft_putchar(tmp->c);
		tmp = tmp->next;
	}
}

static int		ft_check_error(t_line *first)
{
	t_line	*tmp;
	int		word;

	tmp = first;
	while (tmp)
	{
		word = 0;
		while (tmp && tmp->c != ' ')
		{
			word++;
			tmp = tmp->next;
		}
		if (word >= 256)
		{
			write(0, "\n", 1);
			write(0, "42sh: file name too long: ", 26);
			ft_print_error(first);
			write(0, "\n", 1);
			return (-1);
		}
		if (tmp)
			tmp = tmp->next;
	}
	return (1);
}

static void		ft_free_tmp(t_tmp **save, t_data *d)
{
	t_tmp	*ptr;

	if (*save != d->tmp_hist)
	{
		ptr = *save;
		*save = (*save)->next;
		ft_free_list(ptr->line);
		ptr->first = NULL;
		ptr->last = NULL;
		ptr->next = NULL;
		ptr->prev = NULL;
		free(ptr);
	}
	else
	{
		ptr = *save;
		*save = (*save)->next;
		ptr->next = NULL;
		ptr->prev = NULL;
		free(ptr);
	}
}

static void		ft_reset_history(t_data *d)
{
	t_history	*tmp;
	t_tmp		*save;

	if (d->last_hist)
	{
		tmp = d->last_hist;
		tmp->flag = 0;
		tmp = tmp->next;
		while (tmp != d->last_hist)
		{
			tmp->flag = 0;
			tmp = tmp->next;
		}
		d->history = d->first_hist;
		save = d->tmp_hist;
		while (save && save->prev)
			save = save->prev;
		while (save)
			ft_free_tmp(&save, d);
		d->tmp_hist = NULL;
	}
}

int				ft_return(t_data *d)
{
	t_line	*tmp;
	int		i;

	i = 0;
	tmp = d->first;
	ft_reset_history(d);
	ft_history(d);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (ft_check_error(d->first) == -1)
		return (-1);
	tmp = d->first;
	d->str = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (tmp)
	{
		d->str[i++] = tmp->c;
		tmp = tmp->next;
	}
	d->str[i] = '\0';
	write(0, "\n", 1);
	return (-1);
}
