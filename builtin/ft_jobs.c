/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jobs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 12:23:47 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/07 18:31:33 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include "ft_struct.h"

static int	ft_getopt(char **arg)
{
	int		i;

	i = 1;
	while (arg[i] && arg[i][0] == '-')
	{
		if (!ft_strcmp(arg[i], "-p"))
			return (1);
		else
		{
			ft_putstr_fd("42sh: bad option: ", 2);
			ft_putendl_fd(arg[1], 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

int			ft_jobs(t_data *d, char **arg)
{
	t_id		*tmp;
	int			pidopt;

	pidopt = ft_getopt(arg);
	if (pidopt == -1)
		return (1);
	tmp = d->child;
	while (tmp)
	{
		if (tmp->jobs)
		{
			ft_printf("[%d]\t", tmp->nb);
			if (pidopt)
				ft_printf("%d\t", tmp->pid);
			if (tmp->run)
				ft_printf("running\t%s\n", tmp->cmd);
			else
				ft_printf("suspended\t%s\n", tmp->cmd);
		}
		tmp = tmp->next;
	}
	return (0);
}
