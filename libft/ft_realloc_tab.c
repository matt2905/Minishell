/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 10:42:19 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 10:45:41 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		**ft_realloc_tab(char **tab, int len)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * len);
	while (tab && tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
	tmp[i] = NULL;
	return (tmp);
}
