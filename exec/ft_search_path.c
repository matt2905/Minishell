/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:59:01 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/31 14:29:20 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "libft.h"
#include "ft_exec.h"

static char	*ft_check_exe(char *str, char *path, int *flag)
{
	char	*tmp;
	char	*ptr;

	tmp = ft_strjoin(path, "/");
	ptr = tmp;
	tmp = ft_strjoin(tmp, str);
	free(ptr);
	if (access(tmp, F_OK) == -1)
	{
		free(tmp);
		return (NULL);
	}
	if (access(tmp, X_OK) == -1)
	{
		free(tmp);
		*flag = 1;
		ft_putstr_fd("42sh: permission denied: ", 2);
		ft_putendl_fd(str, 2);
		return (NULL);
	}
	return (tmp);
}

static char	*ft_check_direct(char *str, int *flag)
{
	struct stat		buf;
	int				result;
	char			*tmp;

	tmp = ft_strndup(str, ft_strrchr(str, '/') - str + 1);
	stat(str, &buf);
	result = buf.st_mode & S_IFMT;
	if (access(tmp, X_OK) == 0 && access(str, F_OK) == -1)
		return (NULL);
	if (access(tmp, X_OK) == -1 || access(str, X_OK) == -1 || result & S_IFDIR)
	{
		ft_strdel(&tmp);
		*flag = 1;
		ft_putstr_fd("42sh: permission denied: ", 2);
		ft_putendl_fd(str, 2);
		return (NULL);
	}
	ft_strdel(&tmp);
	return (ft_strdup(str));
}

char		*ft_search_path(char **my_env, char *argv, int *flag)
{
	char	*tmp;
	char	**tab;
	int		i;

	if (!ft_strcmp(argv, ".."))
		return (NULL);
	tmp = ft_getenv(my_env, "PATH");
	tab = ft_strsplit(tmp + 5, ':');
	i = -1;
	free(tmp);
	tmp = NULL;
	if (ft_strncmp(argv, "./", 2) && argv[0] != '/')
	{
		while (tab[++i] && tmp == NULL)
		{
			if (access(tab[i], X_OK) == 0)
				tmp = ft_check_exe(argv, tab[i], flag);
		}
	}
	i = 0;
	ft_tabdel(&tab);
	if (tmp == NULL && (!ft_strncmp(argv, "./", 2) || argv[0] == '/'))
		return (ft_check_direct(argv, flag));
	return (tmp);
}
