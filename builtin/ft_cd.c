/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 13:34:42 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/24 11:25:20 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "minishell.h"

static int	ft_check_path(char *str)
{
	if (ft_strcmp(str, "-") == 0)
		return (1);
	if (access(str, F_OK) == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(str);
		return (0);
	}
	if (access(str, X_OK) == -1)
	{
		ft_putstr("cd: permission denied: ");
		ft_putendl(str);
		return (0);
	}
	return (1);
}

static char	*ft_switch_pwd(char **my_env)
{
	char	*tmp;
	char	*buf;

	buf = NULL;
	tmp = ft_getenv(my_env, "OLDPWD");
	if (tmp != NULL)
		return (ft_strdup(tmp + 7));
	tmp = ft_getenv(my_env, "PWD");
	if (tmp == NULL)
		return (ft_strdup(getcwd(buf, 0)));
	else
		return (ft_strdup(tmp + 4));
}

static char	**ft_create_var(char **my_env, char *str, char *var)
{
	int		len;
	char	**tmp;
	char	*ptr;
	int		i;

	i = 0;
	len = ft_tablen(my_env);
	tmp = (char **)malloc(sizeof(char *) * (len + 2));
	while (my_env && my_env[i])
	{
		tmp[i] = ft_strdup(my_env[i]);
		free(my_env[i]);
		i++;
	}
	free(my_env[i]);
	free(my_env);
	ptr = tmp[i];
	tmp[i] = ft_strjoin(var, "=");
	free(ptr);
	ptr = tmp[i];
	tmp[i] = ft_strjoin(tmp[i], str);
	free(ptr);
	tmp[i + 1] = NULL;
	return (tmp);
}

static void	ft_old_pwd(char **old, char **pwd, char **my_env)
{
	char	*buf;

	buf = NULL;
	if ((*old = ft_getenv(my_env, "PWD")))
		*old += 4;
	*pwd = getcwd(buf, 0);
	if (*old == NULL)
		*old = ft_strjoin("OLDPWD=", ft_strdup(*pwd));
	else
		*old = ft_strjoin("OLDPWD=", *old);
	*pwd = ft_strjoin("PWD=", *pwd);
}

static char	**ft_modify_pwd(char **my_env)
{
	int		i;
	char	*old;
	char	*pwd;
	char	*ptr;

	ft_old_pwd(&old, &pwd, my_env);
	if ((i = ft_getenv_pos(my_env, "PWD")) == -1)
		my_env = ft_create_var(my_env, pwd + 4, "PWD");
	else
	{
		ptr = my_env[i];
		my_env[i] = ft_strdup(pwd);
		free(ptr);
	}
	if ((i = ft_getenv_pos(my_env, "OLDPWD")) == -1)
		my_env = ft_create_var(my_env, old, "OLDPWD");
	else
	{
		ptr = my_env[i];
		my_env[i] = ft_strdup(old);
		free(ptr);
	}
	free(old);
	free(pwd);
	return (my_env);
}

char		**ft_cd(char **my_env, char **argv)
{
	char	*ptr;

	if (ft_check_path(argv[1]) != 0)
	{
		if (ft_strcmp(argv[1], "-") == 0)
		{
			ptr = argv[1];
			argv[1] = ft_switch_pwd(my_env);
			free(ptr);
		}
		if (chdir(argv[1]) == -1)
		{
			ft_putstr("cd: not a directory: ");
			ft_putendl(argv[1]);
		}
		else
			my_env = ft_modify_pwd(my_env);
	}
	return (my_env);
}
