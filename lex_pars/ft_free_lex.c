/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 11:30:26 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/28 11:38:11 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lexpars.h"

void	ft_free_lex(t_lexer **lex)
{
	t_lexer		*ptr;

	while (*lex)
	{
		ptr = *lex;
		*lex = (*lex)->next;
		ptr->flag = 0;
		ptr->rank = 0;
		ptr->type = 0;
		ptr->next = NULL;
		ptr->prev = NULL;
		free(ptr);
		ptr = NULL;
	}
}
