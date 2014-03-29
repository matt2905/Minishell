/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 13:41:11 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 17:46:02 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <printf.h>
#include "ft_builtin.h"

static int		ft_get_option(char **str, int *i)
{
	int		flag;
	int		option;

	flag = 1;
	option = 0;
	while (str && str[*i] && flag)
	{
		if (!ft_strcmp(str[*i], "-P"))
			option = 1;
		if (ft_strcmp(str[*i], "-L") && ft_strcmp(str[*i], "-P"))
			flag = 0;
		else
			*i += 1;
	}
	return (option);
}

static char		*ft_get_old_pwd(t_data *d)
{
	char		*tmp;
	char		*ptr;

	tmp = ft_getenv_list(d->my_env, "OLDPWD");
	if (!tmp)
		tmp = ft_strdup(d->save_old);
	ptr = ft_strdup(tmp + 7);
	free(tmp);
	if (access(ptr, F_OK) != -1 && access(ptr, X_OK) != -1)
		ft_printf("%s\n", ptr);
	return (ptr);
}

static char		*ft_check_path(t_data *d, char **argv, int *opt)
{
	char		*tmp;
	char		*ptr;
	char		*pwd;
	int			i;

	i = 1;
	*opt = ft_get_option(argv, &i);
	if (!ft_strcmp(argv[i], "-"))
		return (ft_get_old_pwd(d));
	tmp = ft_getenv_list(d->my_env, "CDPATH");
	if (tmp)
	{
		ptr = tmp;
		tmp = ft_strdup(tmp + 7);
		free(ptr);
	}
	pwd = ft_strdup(d->save_pwd);
	ptr = ft_return_path(d, pwd, tmp, argv[i]);
	ft_strdel(&pwd);
	ft_strdel(&tmp);
	return (ptr);
}

int				ft_cd(t_data *d, char **argv)
{
	char		*path;
	int			opt;

	if ((path = ft_check_path(d, argv, &opt)))
	{
		if (chdir(path) == -1)
		{
			ft_printf("cd: not a directory: %s\n", path);
			ft_strdel(&path);
			return (1);
		}
		else
		{
			ft_modify_pwd(d, path, opt);
			ft_strdel(&path);
			return (0);
		}
	}
	return (1);
}
