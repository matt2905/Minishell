/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 17:14:05 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 18:35:43 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "minishell.h"

static int	ft_is_separator(char c)
{
	if (c == ';' || c == '>' || c == '<' || c == '|' || c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

void		ft_lexer(char *line, t_lex **lex)
{
	int		i;
	int		start;

	i = 0;
	while (line && line[i])
	{
		start = i;
		while (line[i] && ft_is_separator(line[i]) == 0)
			i++;
		if (strncmp(line + start, "\0", i - start))
			ft_add_token(lex, line + start, i - start);
		if (ft_is_separator(line[i]))
			i++;
	}
}
