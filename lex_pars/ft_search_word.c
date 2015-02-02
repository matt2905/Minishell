/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 12:29:44 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/02 10:46:51 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_lexpars.h"

static int	ft_get_end(char *str, int j)
{
	char	c;
	char	save;
	int		ok;

	save = '\0';
	ok = 1;
	while (str[j] && (!ft_isspace(str[j]) || !ok) && ft_check_tok(str[j]))
	{
		c = str[j];
		if (str[j - 1] != '\\' && (c == '\'' || c == '"' || c == '`'))
		{
			if (save == '\0')
				save = c;
			if (c == save)
				ok = 1;
			else
				ok = (ok ? 0 : 1);
		}
		j++;
	}
	return (j);
}

char		*ft_search_word(char **str, int i, char c)
{
	int			j;
	char		*tmp;

	if ((*str)[i] && (*str)[i] == c)
		i++;
	if ((*str)[i] && (*str)[i] == c)
		i++;
	j = i;
	while ((*str)[j] == ' ')
		j++;
	j = ft_get_end(*str, j);
	tmp = ft_strndup((*str) + i, j - i);
	while (i < j)
	{
		(*str)[i] = ' ';
		i++;
	}
	return (tmp);
}
