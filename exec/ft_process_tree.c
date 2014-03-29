/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:59:11 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 20:53:20 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_exec.h"

static const t_exec		g_process[10] =
{
	{1, ft_great},
	{2, ft_dgreat},
	{3, ft_less},
	{4, ft_dless},
	{5, ft_pipe},
	{6, ft_or},
	{7, ft_amp},
	{8, ft_and},
	{9, ft_sep},
	{0, NULL}
};

void				ft_process_tree(t_parser *parser, t_data *d)
{
	int		i;

	i = 0;
	if (parser)
	{
		while (g_process[i].func != NULL && parser->rank != 5)
		{
			if (g_process[i].type == parser->type)
				g_process[i].func(parser, d);
			i++;
		}
		if (parser->rank == 5)
			ft_process(d, parser->str);
	}
}
