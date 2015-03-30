/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 13:40:04 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/30 14:00:39 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_bubble_sort_str(char **tab)
{
	int		i;
	int		j;
	int		ok;
	char	*tmp;

	i = ft_tablen(tab) - 1;
	ok = 1;
	while (i > 0 && ok)
	{
		j = 0;
		ok = 0;
		while (j < i)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
				ok = 1;
			}
			j++;
		}
		i--;
	}
	return (tab);
}
