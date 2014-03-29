/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_shell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 12:34:27 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 21:01:29 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_minishell.h"

static int		ft_search_next_word(char *str, int i, char c)
{
	int		ok;

	ok = 0;
	while (str[++i] && ok == 0)
	{
		while (str[i] && str[i] != c)
			i++;
		if (str[i] == c && str[i - 1] != '\\')
			ok = 1;
	}
	return (i);
}

static int		ft_count_word(char *str)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i])
		{
			word++;
			while (str[i] && !ft_isspace(str[i]))
			{
				if (i > 0 && str[i - 1] != '\\'
						&& (str[i] == '\"' || str[i] == '\''))
					i = ft_search_next_word(str, i, str[i]);
				else
					i++;
			}
		}
	}
	return (word);
}

char			**ft_strsplit_shell(char *str)
{
	int		nb_word;
	int		i;
	char	**tab;

	i = -1;
	if (!str)
		return (NULL);
	nb_word = ft_count_word(str);
	tab = (char **)malloc(sizeof(char *) * (nb_word + 1));
	while (++i < nb_word)
	{
		while (*str && ft_isspace(*str))
			str++;
		tab[i] = ft_get_word(str);
		while (*str && !ft_isspace(*str))
		{
			if (*str - 1 != '\\' && (*str == '\"' || *str == '\''))
				str += ft_search_next_word(str, 0, *str);
			else
				str++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
