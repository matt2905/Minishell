/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:45:05 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 18:50:43 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "minishell.h"

static t_lex	*ft_new_token(char *line, int end)
{
	t_lex	*new;

	new = (t_lex *)malloc(sizeof(t_lex));
	new->next = NULL;
	new->token = ft_strndup(line, end);
	return (new);
}

void			ft_add_token(t_lex **lex, char *line, int end)
{
	if (*lex == NULL)
		*lex = ft_new_token(line, end);
	else
		ft_add_token(&((*lex)->next), line, end);
}
