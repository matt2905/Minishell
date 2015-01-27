/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 11:56:50 by mmartin           #+#    #+#             */
/*   Updated: 2014/06/04 12:17:17 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_tabrealloc(char ***tab, char *str, size_t size)
{
	char	**new;
	int		i;

	i = 0;
	new = (char **)malloc(sizeof(char *) * (size + 1));
	while ((*tab) && (*tab)[i])
	{
		new[i] = ft_strdup((*tab)[i]);
		i++;
	}
	new[i++] = ft_strdup(str);
	new[i] = NULL;
	ft_tabdel(tab);
	return (new);
}
