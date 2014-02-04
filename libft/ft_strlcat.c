/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:52:01 by mmartin           #+#    #+#             */
/*   Updated: 2013/12/06 17:28:43 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	char	*end;

	if (size == 0)
		return (0);
	end = ft_memchr(dst, '\0', size);
	if (end == NULL)
		return (size + ft_strlen(src));
	len = end - dst + ft_strlen(src) + 1;
	if (len >= size)
		len = size - 1;
	ft_memcpy(end, src, len - (size_t)(end - dst));
	dst[len] = '\0';
	return (end - dst + ft_strlen(src));
}
