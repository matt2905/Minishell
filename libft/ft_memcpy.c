/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:52:57 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/16 16:31:48 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*src;

	i = -1;
	dst = (char *)s1;
	src = (const char *)s2;
	while (++i < n)
		dst[i] = src[i];
	return (dst);
}
