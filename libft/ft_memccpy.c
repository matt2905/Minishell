/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:23:41 by mmartin           #+#    #+#             */
/*   Updated: 2013/12/06 17:22:40 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*dst;
	const char		*src;
	unsigned char	ch;

	dst = s1;
	src = s2;
	while (n != 0)
	{
		*dst++ = ch = *src++;
		if (ch == (unsigned char)c)
			return (dst);
		n--;
	}
	return (NULL);
}
