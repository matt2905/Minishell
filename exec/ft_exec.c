/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:57:21 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/11 14:41:02 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "printf.h"
#include "ft_exec.h"
#include "ft_minishell.h"

static void		ft_child(t_data *d)
{
	signal(SIGHUP, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGCHLD, SIG_DFL);
	if (setpgid(0, 0) < 0)
		ft_puterror("setpgid in exec/ft_exec.c => line 30 failed\n");
	if (dup(0) == d->tty.fd)
	{
		if (tcsetpgrp(d->tty.fd, getpgrp()) < 0)
			ft_puterror("tcsetpgrp in exec/ft_exec.c => line 32 failed\n");
	}
}

static void		ft_father(t_data *d)
{
	if (setpgid(d->child->pid, d->child->pid) < 0)
		ft_puterror("setpgid in exec/ft_exec.c => line 38 failed\n");
	if (dup(0) == d->tty.fd)
	{
		if (tcsetpgrp(d->tty.fd, getpgid(d->child->pid)) < 0)
			ft_puterror("tcsetpgrp in exec/ft_exec.c => line 40 failed\n");
	}
	if (killpg(getpgid(d->child->pid), SIGCONT) < 0)
		ft_puterror("kill in exec/ft_exec.c => line 42 failed\n");
	waitpid(-d->child->pid, &d->child->id, WUNTRACED);
	if (dup(0) == d->tty.fd)
	{
		if (tcsetpgrp(d->tty.fd, getpgrp()) < 0)
			ft_puterror("tcsetpgrp in exec/ft_exec.c => line 44 failed\n");
	}
	ft_print_process(d, d->child);
}

static int		ft_launch(char **my_env, char **argv, char *path)
{
	t_data				*d;
	t_id				*tmp;

	d = ft_get_data(NULL);
	tmp = d->child;
	ft_add_process(d, d->nb_process, ft_strimplode(argv), fork());
	if (d->child == tmp)
	{
		ft_child(d);
		execve(path, argv, my_env);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_father(d);
		ft_tabdel(&my_env);
		free(path);
		return (1);
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
