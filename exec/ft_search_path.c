/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:59:01 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 18:06:01 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <libft.h>
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
		ft_putendl("Permission denied");
		return (NULL);
	}
	return (tmp);
}

static char	*ft_check_direct(char *str, int *flag)
{
	struct stat		buf;
	int				result;

	stat(str, &buf);
	result = buf.st_mode & S_IFMT;
	if (access(str, F_OK) == -1)
		return (NULL);
	if (access(str, X_OK) == -1 || result & S_IFDIR)
	{
		*flag = 1;
		ft_putendl("Permission denied");
		return (NULL);
	}
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
	while (tab[++i] && tmp == NULL)
		tmp = ft_check_exe(argv, tab[i], flag);
	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
	if (tmp == NULL)
		return (ft_check_direct(argv, flag));
	return (tmp);
}
