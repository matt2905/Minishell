/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:57:21 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/04 17:53:49 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <libft.h>
#include "minishell.h"

int		ft_exec(char **my_env, char **argv)
{
	pid_t	father;
	char	*path;

	if ((path = ft_search_path(my_env, argv[0])) != NULL)
	{
		father = fork();
		if (father > 0)
		{
			wait(&father);
			ft_free_tab(&my_env);
			free(path);
			return (1);
		}
		else
			execve(path, argv, my_env);
	}
	free(path);
	ft_free_tab(&my_env);
	return (0);
}
