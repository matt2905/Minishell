/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 17:12:00 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/23 21:49:08 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <get_next_line.h>
#include <libft.h>
#include "minishell.h"

char	*ft_create_path(void)
{
	int		fd;
	char	*tmp;
	char	*ptr;
	char	*line;
	int		ok;

	ok = 0;
	fd = open("/etc/paths", O_RDONLY);
	tmp = ft_strdup("PATH=");
	while (get_next_line(fd, &line))
	{
		if (ok == 1)
		{
			ptr = tmp;
			tmp = ft_strjoin(tmp, ":");
			free(ptr);
		}
		ptr = tmp;
		tmp = ft_strjoin(tmp, line);
		free(ptr);
		ok = 1;
		free(line);
	}
	return (tmp);
}

char	**ft_create_env(char **my_env)
{
	extern char		**environ;
	int				i;

	i = ft_tablen(environ);
	if (ft_getenv_pos(environ, "PATH") == -1)
		i += 2;
	my_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (environ && environ[i])
	{
		my_env[i] = ft_strdup(environ[i]);
		i++;
	}
	if (ft_getenv_pos(my_env, "PATH") == -1)
		my_env[i++] = ft_strdup(ft_create_path());
	my_env[i] = NULL;
	return (my_env);
}
