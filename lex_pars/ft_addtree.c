/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:41:02 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/28 19:00:16 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lexpars.h"

static t_parser		*ft_create_parser(char *str, int type, int rank)
{
	t_parser		*tmp;

	if ((tmp = (t_parser *)malloc(sizeof(t_parser))) == NULL)
		return (NULL);
	tmp->str = str;
	tmp->type = type;
	tmp->rank = rank;
	tmp->left = NULL;
	tmp->right = NULL;
	return (tmp);
}

void		ft_add_tree(t_parser **tree, t_lexer *tmp, t_lexer *list, t_var v)
{
	if (tmp && tmp->rank == v.check && v.sens == 'r')
	{
		tmp->flag = 0;
		*tree = ft_create_parser(tmp->str, tmp->type, tmp->rank);
		ft_priority(&((*tree)->right), tmp->next, v);
		v.check++;
		v.sens = 'l';
		ft_priority(&((*tree)->left), tmp->prev, v);
	}
	else if (tmp && tmp->rank == v.check && v.sens == 'l')
	{
		tmp->flag = 0;
		*tree = ft_create_parser(tmp->str, tmp->type, tmp->rank);
		ft_priority(&((*tree)->left), tmp->prev, v);
		v.check++;
		v.sens = 'r';
		ft_priority(&((*tree)->right), tmp->next, v);
	}
	else
	{
		v.check++;
		ft_priority(tree, list, v);
	}
}
