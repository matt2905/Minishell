/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 09:05:57 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/31 14:15:41 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = -1;
	if (s == NULL)
		return (NULL);
	if ((str = ft_strnew(len + 1)) == NULL)
		return (NULL);
	while (++i < len)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}
