/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:57:39 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/10 13:36:55 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "printf.h"
#include "ft_exec.h"
#include "ft_minishell.h"

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

static void		ft_check_process_pipe(t_id *first, t_id *second)
{
	if (!WIFEXITED(first->id) || !WIFEXITED(second->id))
	{
		if (!ft_print_process(first))
			ft_printf("42sh: done\t\t\t%s\n", first->cmd);
		if (!ft_print_process(second))
			ft_printf("42sh: done\t\t\t%s\n", second->cmd);
	}
}

void			ft_pipe(t_parser *parser, t_data *d)
{
	int			fd_pipe[2];
	t_id		*first;
	t_id		*second;
	t_id		*tmp;

	d->pipe = 1;
	pipe(fd_pipe);
	tmp = d->child;
	ft_add_process(d, d->nb_process, ft_strdup(parser->left->str), fork());
	if (d->child == tmp)
		ft_left(parser, d, fd_pipe);
	first = d->child;
	ft_add_process(d, d->nb_process, ft_strdup(parser->right->str), fork());
	if (d->child == first)
		ft_right(parser, d, fd_pipe);
	second = d->child;
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	waitpid(first->pid, &first->id, WUNTRACED);
	waitpid(second->pid, &second->id, WUNTRACED);
	ft_check_process_pipe(first, second);
	d->pipe = 0;
}
