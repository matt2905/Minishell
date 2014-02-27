/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 13:52:19 by amorfan           #+#    #+#             */
/*   Updated: 2014/02/27 17:15:23 by mmartin          ###   ########.fr       */
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

static void			ft_priority(t_parser **tree, t_lexer *list, int check, char sens)
{
	t_lexer			*tmp;

	tmp = list;
	if (check > 5 || !tmp)
		return ;
	while (tmp && tmp->rank != check && tmp->flag)
	{
		if (sens == 'r')
			tmp = tmp->next;
		else
			tmp = tmp->prev;
	}
	if (tmp && tmp->rank == check && sens == 'r')
	{
		tmp->flag = 0;
		*tree = ft_create_parser(tmp->str, tmp->type, tmp->rank);
		ft_priority(&((*tree)->right), tmp->next, check, 'r');
		ft_priority(&((*tree)->left), tmp->prev, ++check, 'l');
	}
	else if (tmp && tmp->rank == check && sens == 'l')
	{
		tmp->flag = 0;
		*tree = ft_create_parser(tmp->str, tmp->type, tmp->rank);
		ft_priority(&((*tree)->left), tmp->prev, check, 'l');
		ft_priority(&((*tree)->right), tmp->next, ++check, 'r');
	}
	else
		ft_priority(tree, list, ++check, sens);
}
void			ft_parser(t_parser **tree, t_lexer *list)
{
	ft_priority(tree, list, 1, 'r');
}
