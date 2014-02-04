/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 09:05:57 by mmartin           #+#    #+#             */
/*   Updated: 2013/12/06 17:38:07 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = -1;
	if (s == NULL)
		return (NULL);
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	while (++i < len)
		str[i] = s[start + i];
	return (str);
}
