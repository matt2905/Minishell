/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:47:38 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/27 13:03:53 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_minishell.h"

/*
**			Too do
**		check argument: if it's a function
**		execve with env modify or NULL
*/

static void	ft_error(char *str)
{
	ft_putstr_fd("ft_env: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": no such file or directory", 2);
}

int			ft_env(t_data *d, char **argv)
{
	int		i;
	t_env	*tmp;

	i = 0;
	while (argv[++i])
	{
		if (!ft_strchr(argv[i], '='))
		{
			ft_error(argv[i]);
			return (1);
		}
	}
	tmp = d->my_env;
	while (tmp)
	{
		ft_putendl(tmp->tab);
		tmp = tmp->next;
	}
	i = 0;
	while (argv[++i])
	{
		if (ft_strchr(argv[i], '='))
			ft_putendl(argv[i]);
	}
	return (0);
}
