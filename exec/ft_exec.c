/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:57:21 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/27 11:23:19 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <libft.h>
#include "ft_minishell.h"

int		ft_exec(char **my_env, char **argv)
{
	extern t_id		gl_pid;
	char			*path;
	int				i;

	i = 0;
	if ((path = ft_search_path(my_env, argv[0], &i)) != NULL)
	{
		gl_pid.father = fork();
		if (gl_pid.father > 0)
		{
			wait(&gl_pid.id);
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
