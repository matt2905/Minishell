/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 13:52:19 by amorfan           #+#    #+#             */
/*   Updated: 2015/03/31 14:37:56 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexpars.h"

void		ft_parser(t_parser **tree, t_lexer *list, int check)
{
	t_lexer			*tmp;

	tmp = list;
	if (check > 5 || !tmp)
		return ;
	while (tmp && tmp->rank != check && tmp->flag)
		tmp = tmp->next;
	ft_add_tree(tree, tmp, list, check);
}
