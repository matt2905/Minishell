/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:32:30 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 16:41:11 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <printf.h>
#include "minishell.h"

static int	ft_check_path(char *str)
{
	if (ft_strcmp(str, "-") == 0)
		return (1);
	if (access(str, F_OK) == -1)
	{
		ft_printf("cd: no such file or directory: %s\n", str);
		return (0);
	}
	if (access(str, X_OK) == -1)
	{
		ft_printf("cd: permission denied: %s\n", str);
		return (0);
	}
	return (1);
}

static char	*ft_switch_pwd(t_env **my_env)
{
	char	*tmp;

	tmp = ft_getenv_list(my_env, "OLDPWD");
	if (tmp != NULL)
		return (ft_strdup(tmp + 7));
	tmp = ft_getenv_list(my_env, "PWD");
	if (tmp == NULL)
		return (ft_strdup(getcwd(NULL, 0)));
	else
		return (ft_strdup(tmp + 4));
}

static void	ft_modify_pwd(t_env **my_env)
{
	char	*old;
	char	*pwd;
	char	*tmp[4];

	if ((old = ft_getenv_list(my_env, "PWD")))
		old += 4;
	pwd = getcwd(NULL, 0);
	if (old == NULL)
		old = pwd;
	tmp[0] = "setenv";
	tmp[1] = "PWD";
	tmp[2] = pwd;
	tmp[3] = NULL;
	ft_setenv(my_env, tmp);
	tmp[1] = "OLDPWD";
	tmp[2] = old;
	ft_setenv(my_env, tmp);
}

void		ft_cd(t_env **my_env, char **argv)
{
	if (ft_check_path(argv[1]) != 0)
	{
		if (ft_strcmp(argv[1], "-") == 0)
			argv[1] = ft_switch_pwd(my_env);
		if (chdir(argv[1]) == -1)
			ft_printf("cd: bot a directory: %s\n", argv[1]);
		else
			ft_modify_pwd(my_env);
	}
}
