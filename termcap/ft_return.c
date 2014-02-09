/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 11:05:56 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/07 18:01:26 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "minishell.h"

static void		ft_print_error(t_line *first)
{
	t_line *tmp;

	tmp = first;
	while (tmp)
	{
		ft_putchar(tmp->c);
		tmp = tmp->next;
	}
}

static int	ft_check_error(t_line *first)
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

int				ft_return(t_data *d)
{
	t_line	*tmp;
	int		i;

	i = 0;
	tmp = d->first;
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
