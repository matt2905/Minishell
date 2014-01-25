/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:39:49 by mmartin           #+#    #+#             */
/*   Updated: 2013/12/06 13:25:25 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*strdup;

	i = -1;
	len = ft_strlen(s1) + 1;
	if ((strdup = ft_strnew(len)) == NULL)
		return (NULL);
	while (++i < len)
		strdup[i] = s1[i];
	return (strdup);
}
