/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:55:29 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/26 17:20:36 by mmartin          ###   ########.fr       */
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
		ft_putendl_fd("Too few arguments", 2);
	else if (i == 4 && !ft_isnumber(argv[3]))
		ft_putendl_fd("4th parameter isn't a number", 2);
	else if (i > 4)
		ft_putendl_fd("Too many arguments", 2);
	if (i < 2 || i > 4 || (i == 4 && !ft_isnumber(argv[3])))
	{
		ft_putendl_fd("Usage: setenv <VARIABLE> [value] [1-0]", 2);
		ft_putendl_fd("1 = overwrite, 0 = add", 2);
		return (1);
	}
	return (0);
}

static char		*ft_search_tmp(char *env, char **argv)
{
	int		i;
	char	*tmp;

	i = ft_tablen(argv);
	if (i == 4 && ft_atoi(argv[3]) == 0 && env)
		tmp = ft_xstrjoin("%s:%s", env, argv[2]);
	else if (i == 3 || ((i == 4) && ft_atoi(argv[3]) != 0))
		tmp = ft_xstrjoin("%s=%s", argv[1], argv[2]);
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
