/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 13:52:19 by amorfan           #+#    #+#             */
/*   Updated: 2014/03/07 13:10:08 by mmartin          ###   ########.fr       */
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
