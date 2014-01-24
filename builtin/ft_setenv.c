/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 13:34:06 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/23 21:06:40 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "minishell.h"

static char	**ft_realloc_env(char **my_env, size_t len)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * len);
	while (my_env && my_env[i])
	{
		tmp[i] = ft_strdup(my_env[i]);
		free(my_env[i]);
		i++;
	}
	free(my_env[i]);
	free(my_env);
	tmp[i] = NULL;
	return (tmp);
}

static int	ft_error(char **argv)
{
	int		i;

	i = ft_tablen(argv);
	if (i < 2)
	{
		ft_putendl("Too few arguments");
		return (1);
	}
	if (i > 4)
	{
		ft_putendl("Too many arguments");
		return (1);
	}
	return (0);
}

static char	*x_ft_strjoin(char *s1, char *s2, char *s3)
{
	int		len;
	char	*tmp;
	int		i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	tmp = (char *)malloc(sizeof(*tmp) * (len + 1));
	while (*s1)
		tmp[i++] = *s1++;
	while (*s2)
		tmp[i++] = *s2++;
	while (*s3)
		tmp[i++] = *s3++;
	tmp[i] = '\0';
	return (tmp);
}

static char	*ft_search_tmp(int k, char **argv, char **my_env)
{
	char	*tmp;

	if (ft_tablen(argv) == 4 && ft_atoi(argv[3]) == 0 && k != -1)
		tmp = x_ft_strjoin(my_env[k], ":", argv[2]);
	else if (ft_tablen(argv) == 3
			|| ((ft_tablen(argv) == 4) && ft_atoi(argv[3]) != 0))
		tmp = x_ft_strjoin(argv[1], "=", argv[2]);
	else
		tmp = ft_strjoin(argv[1], "=");
	return (tmp);
}

char		**ft_setenv(char **my_env, char **argv)
{
	int		i;
	int		k;
	char	*tmp;
	char	*ptr;

	if (ft_error(argv) == 1)
		return (my_env);
	k = ft_getenv_pos(my_env, argv[1]);
	tmp = ft_search_tmp(k, argv, my_env);
	if (k == -1)
	{
		i = ft_tablen(my_env);
		my_env = ft_realloc_env(my_env, i + 2);
		ptr = my_env[i];
		my_env[i] = ft_strdup(tmp);
		my_env[i + 1] = NULL;
	}
	else
	{
		ptr = my_env[k];
		my_env[k] = ft_strdup(tmp);
	}
	free(ptr);
	free(tmp);
	return (my_env);
}
