/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 13:52:19 by amorfan           #+#    #+#             */
/*   Updated: 2014/03/05 15:59:34 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lexpars.h"

void		ft_priority(t_parser **tree, t_lexer *list, t_var v)
{
	t_lexer			*tmp;

	tmp = list;
	if (v.check > 5 || !tmp)
		return ;
	while (tmp && tmp->rank != v.check && tmp->flag)
	{
		if (v.sens == 'r')
			tmp = tmp->next;
		else
		{
			if (v.check == 4)
			{
				while (tmp->prev && tmp->flag)
					tmp = tmp->prev;
				tmp = tmp->next;
				v.sens = 'r';
			}
			else
				tmp = tmp->prev;
		}
	}
	ft_add_tree(tree, tmp, list, v);
}

void		ft_parser(t_parser **tree, t_lexer *list)
{
	t_var	v;

	v.check = 1;
	v.sens = 'r';
	ft_priority(tree, list, v);
}
