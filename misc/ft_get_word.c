/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 19:24:19 by mmartin           #+#    #+#             */
/*   Updated: 2015/04/13 14:11:57 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_get_len(char *str, int *len)
{
	int		i;
	int		ok;
	char	c;

	i = -1;
	ok = 0;
	while (str[++i] && (!ft_isspace(str[i])
				|| (ft_isspace(str[i]) && i > 1 && str[i - 1] == '\\')))
	{
		if (str[i] && (str[i] == '\'' || str[i] == '\"') && str[i - 1] != '\\')
		{
			c = str[i];
			while (!ok && str[++i])
			{
				if (str[i] == c && str[i - 1] != '\\')
					ok = 1;
				else
					(*len)++;
			}
		}
		else
			(*len)++;
	}
}

static void		ft_get_quote(char *str, int *i, int *j, char **tmp)
{
	char	*ptr;
	char	c;
	int		ok;

	ok = 0;
	c = str[*i];
	ptr = *tmp;
	while (!ok && str[++(*i)])
	{
		if (str[*i] && str[*i] == c && str[*(i - 1)] != '\\')
			ok = 1;
		else if (str[*i] && str[*i] == c && str[*(i - 1)] == '\\')
		{
			*j -= 1;
			ptr[*j] = str[*i];
			*j += 1;
		}
		else if (str[*i])
		{
			ptr[*j] = str[*i];
			*j += 1;
		}
	}
}

char			*ft_get_word(char *str)
{
	int		len;
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	len = 0;
	ft_get_len(str, &len);
	tmp = ft_strnew(len + 1);
	while (str[++i] && ((!ft_isspace(str[i])
				|| (ft_isspace(str[i]) && i > 1 && str[i - 1] == '\\'))))
	{
		if (str[i])
		{
			if ((str[i] == '\'' || str[i] == '\"') && (
						i == 0 || (i > 1 && str[i - 1] != '\\')))
				ft_get_quote(str, &i, &j, &tmp);
			else if (i > 0 && str[i - 1] == '\\' && --j >= 0)
				tmp[j++] = str[i];
			else
				tmp[j++] = str[i];
		}
	}
	return (tmp);
}
