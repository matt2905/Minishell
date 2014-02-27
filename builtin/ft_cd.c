/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:32:30 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/27 13:06:30 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <printf.h>
#include "ft_builtin.h"

static int		ft_check_path(char *str)
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

static char		*ft_switch_pwd(t_data *d)
{
	char	*tmp;
	char	*ptr;

	tmp = ft_getenv_list(d->my_env, "OLDPWD");
	if (tmp != NULL)
	{
		ptr = tmp;
		tmp = ft_strdup(tmp + 7);
		free(ptr);
	}
	else
	{
		tmp = ft_getenv_list(d->my_env, "PWD");
		ptr = tmp;
		tmp = ft_strdup(tmp + 4);
		free(ptr);
	}
	if (tmp == NULL)
		return (ft_strdup(getcwd(NULL, 0)));
	return (tmp);
}

static void		ft_free(char **old, char **pwd, char **ptr, char ***tab)
{
	free(*old);
	free(*pwd);
	free(*ptr);
	ft_free_tab(tab);
}

static void		ft_modify_pwd(t_data *d)
{
	char	*old;
	char	*pwd;
	char	**tab;
	char	*ptr;

	ptr = ft_getenv_list(d->my_env, "PWD");
	pwd = getcwd(NULL, 0);
	if (ptr == NULL)
		old = ft_strdup(pwd);
	else
		old = ft_strdup(ptr);
	tab = (char **)malloc(sizeof(char *) * 5);
	tab[0] = ft_strdup("setenv");
	tab[1] = ft_strdup("PWD");
	tab[2] = ft_strdup(pwd);
	tab[3] = NULL;
	ft_setenv(d, tab);
	free(tab[1]);
	free(tab[2]);
	tab[1] = ft_strdup("OLDPWD");
	tab[2] = ft_strdup(old);
	ft_setenv(d, tab);
	ft_free(&old, &pwd, &ptr, &tab);
}

int				ft_cd(t_data *d, char **argv)
{
	char		*ptr;

	if (ft_check_path(argv[1]) != 0)
	{
		if (ft_strcmp(argv[1], "-") == 0)
		{
			ptr = argv[1];
			argv[1] = ft_switch_pwd(d);
			free(ptr);
		}
		if (chdir(argv[1]) == -1)
		{
			ft_printf("cd: not a directory: %s\n", argv[1]);
			return (1);
		}
		else
		{
			ft_modify_pwd(d);
			return (0);
		}
	}
	return (1);
}
