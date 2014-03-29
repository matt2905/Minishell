/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:55:29 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 20:47:06 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_builtin.h"

static int		ft_error(char **argv)
{
	int		i;

	i = ft_tablen(argv);
	if (i < 2)
	{
		ft_putendl("Too few arguments");
		ft_putendl("Usage: setenv <VARIABLE> [value] [1-0]");
		ft_putendl("1 = overwrite, 0 = add");
		return (1);
	}
	if (i > 4)
	{
		ft_putendl("Too many arguments");
		return (1);
	}
	return (0);
}

static char		*x_ft_strjoin(char *s1, char *s2, char *s3)
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

static char		*ft_search_tmp(char *env, char **argv)
{
	int		i;
	char	*tmp;

	i = ft_tablen(argv);
	if (i == 4 && ft_atoi(argv[3]) == 0 && env)
		tmp = x_ft_strjoin(env, ":", argv[2]);
	else if (i == 3 || ((i == 4) && ft_atoi(argv[3]) != 0))
		tmp = x_ft_strjoin(argv[1], "=", argv[2]);
	else
		tmp = ft_strjoin(argv[1], "=");
	return (tmp);
}

int				ft_setenv(t_data *d, char **argv)
{
	char	*env;
	char	*tmp;
	t_env	*new;

	new = d->my_env;
	if (ft_error(argv) == 1)
		return (1);
	env = ft_getenv_list(d->my_env, argv[1]);
	tmp = ft_search_tmp(env, argv);
	if (env == NULL)
		ft_add_env(&new, tmp);
	else
		ft_modify_env(&new, tmp, env);
	free(env);
	d->my_env = new;
	return (0);
}
