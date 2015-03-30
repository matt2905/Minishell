/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelblank.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 12:14:42 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/30 11:55:15 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdelblank(char *str)
{
	int		i;
	char	**tab;

	i = 0;
	while (str[i])
	{
		if (str[i] < 31)
			str[i] = 32;
		i++;
	}
	tab = ft_strsplit_space(str);
	free(str);
	str = ft_strimplode(tab);
	ft_tabdel(&tab);
	return (str);
}
