/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_amp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:55:47 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/19 10:24:56 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "printf.h"
#include "ft_exec.h"
#include "ft_minishell.h"

static void		ft_left(t_parser *parser, t_data *d)
{
	d->fork = 1;
	ft_process_tree(parser->left, d);
	exit(EXIT_SUCCESS);
}

static void		ft_right(t_parser *parser, t_data *d)
{
	ft_process_tree(parser->right, d);
	exit(EXIT_SUCCESS);
}

void			ft_amp(t_parser *parser, t_data *d)
{
	t_id		*tmp;
	t_id		*second;
	t_id		*first;

	tmp = d->child;
	ft_add_process(d, d->nb_process, ft_strdup(parser->left->str), fork());
	if (d->child == tmp)
		ft_left(parser, d);
	d->child->run = 1;
	first = d->child;
	if (parser->right)
	{
		ft_add_process(d, d->nb_process, ft_strdup(parser->right->str), fork());
		if (d->child == first)
			ft_right(parser, d);
		second = d->child;
		ft_printf("[%d]\t%d\n", d->child->nb, d->child->pid);
		waitpid(second->pid, &second->id, WUNTRACED);
		waitpid(second->pid, &second->id, WUNTRACED);
	}
}
