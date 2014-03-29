/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_curpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:33:13 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 17:50:58 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <printf.h>
#include "ft_builtin.h"

static char		*ft_get_path(char *dst, char *tmp)
{
	char		*ptr;

	if (dst[0] && dst[1] != '\0')
	{
		dst = ft_strjoin(dst, "/");
		ptr = dst;
		dst = ft_strjoin(dst, tmp);
		free(ptr);
	}
	else
		dst = ft_strjoin(dst, tmp);
	return (dst);
}

static char		*ft_modify_path(char *dst, char *src, int len)
{
	char	*tmp;
	int		i;

	i = 0;
	if (src[len - 1] == '/')
		len--;
	tmp = ft_strndup(src, len);
	if (!ft_strcmp(tmp, ".."))
	{
		free(tmp);
		i = ft_strrchr(dst, '/') - dst;
		if (i == 0)
			i = 1;
		return (ft_strndup(dst, i));
	}
	else if (ft_strcmp(tmp, "."))
	{
		dst = ft_get_path(dst, tmp);
		free(tmp);
		return (dst);
	}
	free(tmp);
	return (ft_strdup(dst));
}

static char		*ft_get_curpath(char *env, char *str)
{
	char	*ptr;
	char	*tmp;
	int		save;
	int		i;

	i = -1;
	save = 0;
	ptr = ft_strdup(env);
	if (str[0] == '/')
	{
		ft_strdel(&ptr);
		return (ft_strdup(str));
	}
	while (str[++i])
	{
		if (str[i] == '/' || str[i + 1] == '\0')
		{
			tmp = ptr;
			ptr = ft_modify_path(ptr, str + save, i - save + 1);
			ft_strdel(&tmp);
			save = i + 1;
		}
	}
	return (ptr);
}

static void		ft_is_valid_path(char **path, char *str, char *tmp)
{
	if (*path == NULL)
		return ;
	if (access(*path, F_OK) != -1)
	{
		if (access(*path, X_OK) != -1)
			return ;
		else if (!tmp)
			ft_printf("cd: permission denied: %s\n", str);
	}
	else if (!tmp)
		ft_printf("cd: no such file or directory: %s\n", str);
	ft_strdel(path);
}

char			*ft_return_path(t_data *d, char *pwd, char *tmp, char *str)
{
	char	*path;
	char	*ptr;

	if (!str)
	{
		if ((ptr = ft_getenv_list(d->my_env, "HOME")) == NULL)
			return (NULL);
		path = ft_strdup(ptr + 5);
		free(ptr);
	}
	else
		path = ft_get_curpath(pwd, str);
	ft_is_valid_path(&path, str, tmp);
	if (path)
		return (path);
	else if (tmp)
	{
		path = ft_get_curpath(tmp, str);
		ft_is_valid_path(&path, str, NULL);
		return (path);
	}
	return (NULL);
}
