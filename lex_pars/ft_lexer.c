/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:31:04 by amorfan           #+#    #+#             */
/*   Updated: 2014/03/02 11:23:20 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_lexpars.h"

static const t_token	tok[10] =
{
	{'>', 1, 4},
	{'>', 2, 4},
	{'<', 3, 4},
	{'<', 4, 4},
	{'|', 5, 3},
	{'|', 6, 2},
	{'&', 7, 1},
	{'&', 8, 2},
	{';', 9, 1},
	{'\0', 0, 0}
};

static int				ft_check_tok(char c)
{
	int			i;

	i = 0;
	while (tok[i].type != 0)
	{
		if (c == tok[i].c)
			return (0);
		i++;
	}
	return (1);
}

static char				*ft_search_word(char **str, int i, char c)
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
	while ((*str)[j] != ' ' && ft_check_tok((*str)[j]) && (*str)[j])
		j++;
	tmp = ft_strndup((*str) + i, j - i);
	while (i < j)
	{
		(*str)[i] = ' ';
		i++;
	}
	return (tmp);
}

void					ft_lexer(t_lexer **root, char *str)
{
	int			i;
	int			j;

	i = -1;
	j = 9;
	while (j == 9 && str[++i])
	{
		j = 0;
		while (str[i] != tok[j].c && tok[j].type != 0)
			j++;
	}
	if (*root == NULL && !str[i])
		return ;
	if (tok[j].rank == 4)
	{
		ft_add_lexer(root, ft_search_word(&str, i, tok[j].c), 0, 5);
		if (str[i] && str[i + 1] && str[i] == str[i + 1])
		{
			j++;
			ft_add_lexer(root, ft_strndup(str + i++, 2), tok[j].type, tok[j].rank);
			str[i - 1] = ' ';
			str[i] = ' ';
		}
		else if (str[i])
		{
			ft_add_lexer(root, ft_strndup(str + i, 1), tok[j].type, tok[j].rank);
			str[i] = ' ';
		}
		if (str[i])
			ft_lexer(root, str);
	}
	else
	{
		ft_add_lexer(root, ft_strndup(str, i), 0, 5);
		if (str[i] && str[i + 1] && str[i] == str[i + 1] && tok[j].type <= 7)
		{
			j++;
			ft_add_lexer(root, ft_strndup(str + i++, 2), tok[j].type, tok[j].rank);
		}
		else if (str[i] && tok[j].type > 0)
			ft_add_lexer(root, ft_strndup(str + i, 1), tok[j].type, tok[j].rank);
		if (str[i] && *(str + i + 1))
			ft_lexer(root, str + i + 1);
	}
}
