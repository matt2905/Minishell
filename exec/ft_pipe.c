/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:57:39 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/12 15:07:04 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "ft_exec.h"

static void		ft_left(t_parser *parser, t_data *d, int *fd_pipe)
{
	d->fork = 1;
	close(fd_pipe[0]);
	dup2(fd_pipe[1], 1);
	ft_process_tree(parser->left, d);
	exit(1);
}

static void		ft_right(t_parser *parser, t_data *d, int *fd_pipe)
{
	d->fork = 1;
	close(fd_pipe[1]);
	dup2(fd_pipe[0], 0);
	dup2(d->save_fd[1], 1);
	ft_process_tree(parser->right, d);
	exit(1);
}

void			ft_pipe(t_parser *parser, t_data *d)
{
	extern t_id		g_pid;
	int				fd_pipe[2];
	pid_t			child1;
	int				id;

	d->pipe = 1;
	pipe(fd_pipe);
	child1 = fork();
	if (child1 == 0)
		ft_left(parser, d, fd_pipe);
	g_pid.father = fork();
	if (g_pid.father == 0)
		ft_right(parser, d, fd_pipe);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	waitpid(child1, &id, 0);
	waitpid(g_pid.father, &g_pid.id, 0);
	d->pipe = 0;
}
