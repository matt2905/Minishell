/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 13:24:12 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/04 19:20:11 by mmartin          ###   ########.fr       */
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
		free(line);
		ok = 1;
	}
	return (tmp);
}

void	ft_create_env(t_env **env)
{
	extern char	**environ;
	int			i;
	int			flag;

	i = 0;
	flag = 0;
	while (environ && environ[i])
	{
		ft_add_env(env, ft_strdup(environ[i]));
		if (flag == 0 && ft_strncmp(environ[i], "PATH", 4) == 0)
			flag = 1;
		i++;
	}
	if (flag == 0)
		ft_add_env(env, ft_create_path());
}
