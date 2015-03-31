/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 11:05:56 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/31 14:00:51 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_history.h"
#include "ft_termcap.h"

static int		ft_check_error(t_line *first)
{
	int		word;
	int		i;

	i = 0;
	while (first->str && first->str[i])
	{
		word = 0;
		while (first->str[i] && first->str[i] != ' ')
		{
			word++;
			i++;
		}
		if (word >= 256)
		{
			ft_putstr_fd("\n42sh: file name too long: ", 2);
			ft_putendl_fd(first->str, 2);
			return (-1);
		}
		if (first->str[i])
			i++;
	}
	return (1);
}

int				ft_return(t_data *d)
{
	d->signal = 0;
	ft_end(d);
	ft_reset_history(d);
	ft_history(d);
	if (ft_check_error(d->line) == -1)
		return (-1);
	d->str = ft_strdup(d->line->str);
	write(0, "\n", 1);
	return (-1);
}
