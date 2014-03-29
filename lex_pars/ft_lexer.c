/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:31:04 by amorfan           #+#    #+#             */
/*   Updated: 2014/03/27 13:47:44 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_lexpars.h"

static const t_token	g_t[10] =
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

static void			ft_redirection(t_lexer **root, char *str, int i, int j)
{
	ft_add_lexer(root, ft_search_word(&str, i, g_t[j].c), 0, 5);
	if (str[i] && str[i + 1] && str[i] == str[i + 1])
	{
		j++;
		ft_add_lexer(root, ft_strndup(str + i++, 2), g_t[j].type, g_t[j].rank);
		str[i - 1] = ' ';
		str[i] = ' ';
	}
	else if (str[i])
	{
		ft_add_lexer(root, ft_strndup(str + i, 1), g_t[j].type, g_t[j].rank);
		str[i] = ' ';
	}
	if (str[i])
		ft_lexer(root, str);
}

static void			ft_other(t_lexer **root, char *str, int i, int j)
{
	ft_add_lexer(root, ft_strndup(str, i), 0, 5);
	if (str[i] && str[i + 1] && str[i] == str[i + 1] && g_t[j].type <= 7)
	{
		j++;
		ft_add_lexer(root, ft_strndup(str + i++, 2), g_t[j].type, g_t[j].rank);
	}
	else if (str[i] && g_t[j].type > 0)
		ft_add_lexer(root, ft_strndup(str + i, 1), g_t[j].type, g_t[j].rank);
	if (str[i] && *(str + i + 1))
		ft_lexer(root, str + i + 1);
}

int					ft_check_tok(char c)
{
	int			i;

	i = 0;
	while (g_t[i].type != 0)
	{
		if (c == g_t[i].c)
			return (0);
		i++;
	}
	return (1);
}

static int			ft_get_pos(char *str, int i)
{
	int			ok;
	char		c;

	ok = 0;
	if (str[i] == '\"' || str[i] == '\'')
	{
		if (i == 0 || (i > 0 && str[i - 1] != '\\'))
		{
			c = str[i];
			while (str[++i] && !ok)
			{
				while (str[i] && str[i] != c)
					i++;
				if (str[i] == c && str[i - 1] != '\\')
					ok++;
			}
		}
	}
	return (i);
}

void				ft_lexer(t_lexer **root, char *str)
{
	int			i;
	int			j;

	i = -1;
	j = 9;
	while (j == 9 && str[++i])
	{
		j = 0;
		i = ft_get_pos(str, i);
		while (str[i] != g_t[j].c && g_t[j].type != 0)
			j++;
		if (j < 9 && i > 0 && str[i - 1] == '\\')
			j = 9;
	}
	if (*root == NULL && !str[i])
		return ;
	if (g_t[j].rank == 4)
		ft_redirection(root, str, i, j);
	else
		ft_other(root, str, i, j);
}
