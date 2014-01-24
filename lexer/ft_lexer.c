/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 17:14:05 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/24 15:53:09 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "minishell.h"

void		ft_lexer(char *line, t_lex **lex)
{
	int		i;
	int		start;

	i = 0;
	while (line && line[i])
	{
		start = i;
		while (line[i] != '\0' && line[i] != ';')
			i++;
		ft_add_token(lex, line, start, i);
		if (line[i] == ';')
			i++;
	}
}
