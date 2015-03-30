/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:25:05 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/27 17:27:39 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnrchr(const char *s, int c, size_t len)
{
	char	*save;
	size_t	i;

	i = 0;
	save = NULL;
	while (s[i] && i < len)
	{
		if (s[i] == c)
			save = (char *)(s + i);
		i++;
	}
	return (save);
}
