/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:57:39 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/04 16:00:27 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "printf.h"
#include "ft_exec.h"

static void		ft_left(t_parser *parser, t_data *d, int *fd_pipe)
{
	d->fork = 1;
	close(fd_pipe[0]);
	dup2(fd_pipe[1], 1);
	ft_process_tree(parser->left, d);
	exit(EXIT_SUCCESS);
}

static void		ft_right(t_parser *parser, t_data *d, int *fd_pipe)
{
	d->fork = 1;
	close(fd_pipe[1]);
	dup2(fd_pipe[0], 0);
	dup2(d->save_fd[1], 1);
	ft_process_tree(parser->right, d);
	exit(EXIT_SUCCESS);
}

static void		ft_check_process(t_id g_pid, int id)
{
	extern const char	*sys_siglist[];
	char				*cmd;

	if (!WIFEXITED(g_pid.id) || !WIFEXITED(id))
	{
		cmd = ft_itoa(g_pid.child, 10);
		if (WIFSIGNALED(id))
			ft_printf("42sh: %s\t%s\n", sys_siglist[WTERMSIG(id)], cmd);
		else
			ft_printf("42sh: done\t\t\t%s\n", cmd);
		ft_strdel(&cmd);
		cmd = ft_itoa(g_pid.father, 10);
		if (WIFSIGNALED(g_pid.id))
			ft_printf("42sh: %s\t%s\n", sys_siglist[WTERMSIG(g_pid.id)], cmd);
		else
			ft_printf("42sh: done\t\t\t%s\n", cmd);
		ft_strdel(&cmd);
	}
}

void			ft_pipe(t_parser *parser, t_data *d)
{
	extern t_id		g_pid;
	int				fd_pipe[2];
	int				id;

	d->pipe = 1;
	pipe(fd_pipe);
	g_pid.child = fork();
	if (g_pid.child == 0)
		ft_left(parser, d, fd_pipe);
	g_pid.father = fork();
	if (g_pid.father == 0)
		ft_right(parser, d, fd_pipe);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	waitpid(g_pid.child, &id, 0);
	waitpid(g_pid.father, &g_pid.id, 0);
	ft_check_process(g_pid, id);
	d->pipe = 0;
}
