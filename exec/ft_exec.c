/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:57:21 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/05 19:41:38 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <libft.h>
#include "ft_exec.h"

static int	ft_launch(char **my_env, char **argv, char *path)
{
	extern t_id		g_pid;

	g_pid.father = fork();
	if (g_pid.father > 0)
	{
		wait(&g_pid.id);
		ft_free_tab(&my_env);
		free(path);
		return (1);
	}
	else
		execve(path, argv, my_env);
	return (0);
}

int		ft_exec(char **my_env, char **argv, int ok)
{
	extern t_id		g_pid;
	char			*path;
	int				i;

	i = 0;
	g_pid.father = 0;
	g_pid.id = 0;
	if ((path = ft_search_path(my_env, argv[0], &i)) != NULL)
	{
		if (ok == 0)
		{
			if (ft_launch(my_env, argv, path) == 1)
				return (1);
		}
		else
		{
			execve(path, argv, my_env);
			ft_putendl("test\n");
		}
	}
	free(path);
	ft_free_tab(&my_env);
	return (i);
}
