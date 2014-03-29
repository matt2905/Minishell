/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:56:19 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 12:13:36 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "ft_exec.h"

void	ft_and(t_parser *parser, t_data *d)
{
	extern t_id		g_pid;

	ft_process_tree(parser->left, d);
	if (g_pid.built == 0)
		ft_process_tree(parser->right, d);
	else if (g_pid.father != 0)
	{
		if (WIFEXITED(g_pid.id) && WEXITSTATUS(g_pid.id) == 0)
			ft_process_tree(parser->right, d);
	}
}
