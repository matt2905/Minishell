/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 11:05:56 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/06 20:01:39 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "minishell.h"

static void		ft_print_list(t_line *first)
{
	t_line *tmp;

	tmp = first;
	while (tmp)
	{
		ft_putchar(tmp->c);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

int				ft_return(t_data *d)
{
	t_line	*tmp;
	int		i;

	i = 0;
	tmp = d->first;
	while (tmp && (tmp = tmp->next))
		i++;
	if (i > 256)
	{
		ft_putchar('\n');
		ft_putstr("42sh: file name to long:");
		ft_print_list(d->first);
		exit(EXIT_FAILURE);
	}
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
