/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 17:14:05 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/24 16:52:26 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "minishell.h"

static void	ft_lexer_ope(t_lex **lex, char *line, int end)
{
	int		i;
	int		start;

	i = 0;
	while (line && line[i] && i < end)
	{
		start = i;
		while (line[i] && line[i] != '|')
			i++;
		ft_add_token(lex, line + start, i - start - 1);
		if (line[i] == '|')
			i++;
	}
}

void		ft_lexer_sep(char *line, t_lex **lex)
{
	int		i;
	int		start;

	i = 0;
	while (line && line[i])
	{
		start = i;
		while (line[i] && line[i] != ';')
			i++;
		ft_lexer_ope(lex, line + start, i - start - 1);
		if (line[i] == ';')
			i++;
	}
}
