/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:57:21 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/04 18:10:46 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "printf.h"
#include "ft_exec.h"
#include "ft_minishell.h"

static int		ft_launch(char **my_env, char **argv, char *path)
{
	extern const char	*sys_siglist[];
	t_data				*d;
	t_id				*tmp;

	d = ft_get_data(NULL);
	tmp = d->child;
	ft_add_process(d, d->nb_process, ft_strimplode(argv), fork());
	if (d->child != tmp)
	{
		waitpid(d->child->pid, &d->child->id, WUNTRACED);
		if (WIFSIGNALED(d->child->id))
		{
			ft_printf("42sh: %s\t%s\n",
					sys_siglist[WTERMSIG(d->child->id)], d->child->cmd);
		}
		ft_tabdel(&my_env);
		free(path);
		return (1);
	}
	else
	{
		execve(path, argv, my_env);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int				ft_exec(char **my_env, char **argv, int ok)
{
	char	*path;
	int		i;

	i = 0;
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
