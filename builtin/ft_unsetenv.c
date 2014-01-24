/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 12:18:14 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/23 21:30:02 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "minishell.h"

static int	ft_error(char **argv)
{
	int		i;

	i = ft_tablen(argv);
	if (i < 2)
	{
		ft_putendl("Too few arguments");
		return (1);
	}
	return (0);
}

static char	**ft_delete(char **my_env, int k)
{
	char	**tmp;
	int		i;
	int		j;

	j = -1;
	i = ft_tablen(my_env);
	tmp = (char **)malloc(sizeof(char *) * i);
	i = -1;
	while (my_env && my_env[++i])
	{
		if (i != k)
			tmp[++j] = ft_strdup(my_env[i]);
		free(my_env[i]);
	}
	free(my_env[i]);
	free(my_env);
	tmp[++j] = NULL;
	return (tmp);
}

char		**ft_unsetenv(char **my_env, char **argv)
{
	int		i;
	int		k;

	i = 1;
	if (ft_error(argv) == 1)
		return (my_env);
	while (argv[i])
	{
		k = 0;
		while (my_env && my_env[k])
		{
			if (ft_strncmp(argv[i], my_env[k], ft_strlen(argv[i])) == 0)
				my_env = ft_delete(my_env, k);
			k++;
		}
		i++;
	}
	return (my_env);
}
