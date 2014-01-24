/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 13:29:58 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/22 18:03:34 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "minishell.h"

static char	**ft_error(char *str, char **my_env)
{
	ft_putstr_fd("ft_env : ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": No such file or directory", 2);
	return (my_env);
}

char		**ft_env(char **my_env, char **argv)
{
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (!ft_strchr(argv[i], '='))
			return (ft_error(argv[i], my_env));
	}
	i = 0;
	while (my_env[i])
	{
		ft_putendl(my_env[i]);
		i++;
	}
	i = 0;
	while (argv[++i])
	{
		if (ft_strchr(argv[i], '='))
			ft_putendl(argv[i]);
	}
	return (my_env);
}
