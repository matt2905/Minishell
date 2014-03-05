/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:57:21 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/05 11:13:16 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <libft.h>
#include "ft_exec.h"

int		ft_exec(char **my_env, char **argv)
{
	extern t_id		g_pid;
	char			*path;
	int				i;

	i = 0;
	g_pid.father = 0;
	g_pid.id = 0;
	if ((path = ft_search_path(my_env, argv[0], &i)) != NULL)
	{
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
	}
	free(path);
	ft_free_tab(&my_env);
	return (i);
}
