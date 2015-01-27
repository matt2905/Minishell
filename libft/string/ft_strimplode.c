/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strimplode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 11:18:01 by mmartin           #+#    #+#             */
/*   Updated: 2014/06/26 11:27:58 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strimplode(char **tab)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (tab && tab[++i])
		len += ft_strlen(tab[i]);
	if (!len || !(str = ft_strnew(len + i)))
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		ft_strcat(str, tab[i]);
		len = ft_strlen(str);
		str[len] = ' ';
	}
	str[len] = '\0';
	return (str);
}
