/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:32:30 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/16 18:08:10 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <printf.h>
#include "ft_builtin.h"

static char		*ft_check_cdpath(char **tmp, char *str)
{
	char	*ptr;

	ptr = ft_strjoin(*tmp + 7, "/");
	free(*tmp);
	*tmp = ft_strjoin(ptr, str);
	free(ptr);
	if (access(*tmp, F_OK) == -1)
	{
		ft_printf("cd: no such file or directory: %s\n", str);
		return (NULL);
	}
	if (access(*tmp, X_OK) == -1)
	{
		ft_printf("cd: permission denied: %s\n", str);
		return (NULL);
	}
	ft_printf("%s\n", *tmp);
	return (*tmp);
}

static char		*ft_check_path(t_data *d, char *str)
{
	char	*tmp;

	if (!ft_strcmp(str, "-"))
		return (ft_strdup(str));
	tmp = ft_getenv_list(d->my_env, "CDPATH");
	if (access(str, F_OK) != -1)
	{
		if (access(str, X_OK) != -1)
			return (ft_strdup(str));
		else if (!tmp)
		{
			ft_printf("cd: permission denied: %s\n", str);
			return (NULL);
		}
	}
	else if (!tmp)
	{
		ft_printf("cd: no such file or directory: %s\n", str);
		return (NULL);
	}
	return (ft_check_cdpath(&tmp, str));
}

static char		*ft_inverse_pwd(t_data *d)
{
	char	*tmp;
	char	*ptr;

	tmp = ft_getenv_list(d->my_env, "OLDPWD");
	if (tmp)
	{
		ptr = tmp;
		tmp = ft_strdup(tmp + 7);
		free(ptr);
	}
	else
	{
		tmp = ft_getenv_list(d->my_env, "PWD");
		if (!tmp)
		{
			ptr = getcwd(NULL, 0);
			tmp = ft_strdup(ptr + 9);
			free(ptr);
		}
		ptr = tmp;
		tmp = ft_strdup(tmp + 4);
		free(ptr);
	}
	ft_printf("%s\n", tmp);
	return (tmp);
}

int				ft_cd(t_data *d, char **argv)
{
	char	*path;
	char	*ptr;

	if ((path = ft_check_path(d, argv[1])))
	{
		if (!ft_strcmp(path, "-"))
		{
			ptr = path;
			path = ft_inverse_pwd(d);
			free(ptr);
		}
		if (chdir(path) == -1)
		{
			ft_printf("cd: not a directory: %s\n", path);
			free(path);
			return (1);
		}
		else
		{
			ft_modify_pwd(d);
			free(path);
			return (0);
		}
	}
	return (1);
}
