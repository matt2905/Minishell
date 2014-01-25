/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnsplit_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:02:37 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 18:19:44 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

static int	ft_count_word(char *str, int n)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (str[i] && i < n)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t') && i < n)
			i++;
		if (str[i] && i < n)
		{
			word++;
			while (str[i] && str[i] != ' ' && str[i] != '\t' && i < n)
				i++;
		}
	}
	return (word);
}

static int	ft_len_word(char *str)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		i++;
		k++;
	}
	return (k);
}

static char	*ft_get_str(char *str, int n)
{
	char	*tmp;
	int		i;

	i = ft_len_word(str);
	tmp = (char *)malloc(sizeof(*tmp) * (i + 1));
	i = 0;
	while (*str && *str != ' ' && *str != '\t' && i < n)
	{
		tmp[i] = *str;
		i++;
		str++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char		**ft_strnsplit_space(char *str, int n)
{
	int		nb_word;
	int		i;
	char	**tab;

	i = -1;
	nb_word = ft_count_word(str, n);
	tab = (char **)malloc(sizeof(char *) * nb_word + 1);
	while (++i < nb_word)
	{
		while (*str && (*str == ' ' || *str == '\t'))
		{
			n--;
			str++;
		}
		tab[i] = ft_get_str(str, n);
		while (*str && *str != ' ' && *str != '\t')
		{
			n--;
			str++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
