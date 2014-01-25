/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_lex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 12:10:40 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 18:36:45 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

void		ft_destroy_lex(t_lex **lex)
{
	t_lex	*tmp;

	while (*lex != NULL)
	{
		tmp = *lex;
		*lex = (*lex)->next;
		free(tmp->token);
		free(tmp);
	}
}
