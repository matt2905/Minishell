/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 15:26:38 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/01 16:27:37 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charcasecmp(char c1, char c2)
{
	if (ft_islower(c1) && ft_isupper(c2))
		return (c1 - (c2 + 32));
	if (ft_isupper(c1) && ft_islower(c2))
		return ((c1 + 32) - c2);
	return (c1 - c2);
}

int			ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			if (ft_charcasecmp(s1[i], s2[i]))
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		else if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
