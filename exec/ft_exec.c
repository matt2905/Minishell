/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:57:21 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/24 11:05:20 by mmartin          ###   ########.fr       */
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
			free(path);
			return (1);
		}
		else
			execve(path, argv, my_env);
	}
	free(path);
	return (0);
}
