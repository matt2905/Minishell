/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:31:04 by amorfan           #+#    #+#             */
/*   Updated: 2014/02/27 17:16:14 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lexpars.h"

static t_lexer	*ft_create_lexer(char *str, int type, int rank)
{
	t_lexer		*tmp;
	if ((tmp = (t_lexer *)malloc(sizeof(t_lexer))) == NULL)
		return (NULL);
	tmp->str = str;
	tmp->type = type;
	tmp->rank = rank;
	tmp->flag = 1;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

void			ft_add_lexer(t_lexer **root, char *str, int type, int rank)
{
//	if (str == NULL || *str == '\0')
//	{
//		ft_printf("42sh : parse error biatch\n");
//		exit(EXIT_FAILURE);
//	}
	if (*root == NULL)
		*root = ft_create_lexer(str, type, rank);
	else
	{
		ft_add_lexer(&((*root)->next), str, type, rank);
		if ((*root)->next->prev == NULL)
			(*root)->next->prev = *root;
	}
}
