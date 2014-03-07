/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:41:02 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/07 13:09:47 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lexpars.h"

t_parser	*ft_create_parser(char *str, int type, int rank)
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

void		ft_add_tree(t_parser **tree, t_lexer *tmp, t_lexer *list, int check)
{
	if (tmp && tmp->rank == check)
	{
		tmp->flag = 0;
		*tree = ft_create_parser(tmp->str, tmp->type, tmp->rank);
		ft_parser(&((*tree)->right), tmp->next, check);
		check++;
		ft_parser(&((*tree)->left), list, check);
	}
	else
	{
		check++;
		ft_parser(tree, list, check);
	}
}
