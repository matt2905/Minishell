/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:57:33 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/05 11:16:36 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "ft_exec.h"

void	ft_or(t_parser *parser, t_data *d)
{
	extern t_id		g_pid;

	ft_process_tree(parser->left, d);
	if (WIFSIGNALED(g_pid.id) || g_pid.built == 1)
		ft_process_tree(parser->right, d);
	else if (g_pid.father != 0)
	{
		if (WIFEXITED(g_pid.id) && WEXITSTATUS(g_pid.id) > 0)
			ft_process_tree(parser->right, d);
	}
	g_pid.father = 0;
	g_pid.id = 0;
	g_pid.built = -1;
}
