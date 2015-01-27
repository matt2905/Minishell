/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:23:41 by mmartin           #+#    #+#             */
/*   Updated: 2015/01/23 15:30:38 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*dst;
	const char		*src;
	unsigned char	ch;

	dst = (char *)s1;
	src = (const char *)s2;
	while (n != 0)
	{
		ch = *src++;
		*dst++ = ch;
		if (ch == (unsigned char)c)
			return (dst);
		n--;
	}
	return (NULL);
}
