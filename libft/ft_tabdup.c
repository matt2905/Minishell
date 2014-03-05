/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 17:48:38 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/05 10:27:57 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_tabdup(char **tab)
{
	int		len;
	int		i;
	char	**new;

	i = -1;
	len = ft_tablen(tab);
	if ((new = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	while (++i < len)
		new[i] = ft_strdup(tab[i]);
	new[i] = NULL;
	return (new);
}
