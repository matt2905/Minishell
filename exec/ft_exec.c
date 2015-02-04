/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:57:21 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/04 15:45:15 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "printf.h"
#include "ft_exec.h"

static int		ft_launch(char **my_env, char **argv, char *path)
{
	extern const char	*sys_siglist[];
	extern t_id			g_pid;
	char				*cmd;

	g_pid.father = fork();
	if (g_pid.father > 0)
	{
		waitpid(g_pid.father, &g_pid.id, WUNTRACED);
		if (WIFSIGNALED(g_pid.id))
		{
			cmd = ft_strimplode(argv);
			ft_printf("42sh: %s\t%s\n", sys_siglist[WTERMSIG(g_pid.id)], cmd);
			ft_strdel(&cmd);
		}
		ft_tabdel(&my_env);
		free(path);
		return (1);
	}
	else
	{
		if (execve(path, argv, my_env) == -1)
			exit(EXIT_FAILURE);
	}
	return (0);
}

int				ft_exec(char **my_env, char **argv, int ok)
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
			if (execve(path, argv, my_env) == -1)
				exit(EXIT_FAILURE);
		}
	}
	ft_strdel(&path);
	ft_tabdel(&my_env);
	return (i);
}
