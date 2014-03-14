/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 19:24:19 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/12 20:15:44 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_get_len(char *str)
{
	int		i;
	int		ok;
	int		len;
	char	c;

	i = -1;
	ok = 0;
	len = 0;
	while (str[++i] && !ft_isspace(str[i]))
	{
		if (str[i] && (str[i] == '\'' || str[i] == '\"') && str[i - 1] != '\\')
		{
			c = str[i];
			while (str[++i] && ok == 0)
			{
				if (str[i] == c && str[i - 1] != '\\')
					ok = 1;
				else
					len++;
			}
		}
		else
			len++;
	}
	return (len);
}

void	ft_get_quote(char *str, int *i, int *j, char **tmp)
{
	char	*ptr;
	char	c;
	int		ok;

	ok = 0;
	c = str[*i];
	*i += 1;
	ptr = *tmp;
	while (str[*i] && ok == 0)
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
		*i += 1;
	}
}

char	*ft_get_word(char *str)
{
	int		len;
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	len = ft_get_len(str);
	tmp = ft_strnew(len + 1);
	while (str[++i] && !ft_isspace(str[i]))
	{
		if (str[i])
		{
			if ((str[i] == '\'' || str[i] == '\"') && str[i - 1] != '\\')
				ft_get_quote(str, &i, &j, &tmp);
			else if ((str[i] == '\'' || str[i] == '\"') && str[i - 1] == '\\')
			{
				j--;
				tmp[j++] = str[i];
			}
			else
				tmp[j++] = str[i];
		}
	}
	return (tmp);
}
