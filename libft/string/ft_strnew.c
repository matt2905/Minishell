/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 17:36:24 by mmartin           #+#    #+#             */
/*   Updated: 2013/12/07 19:28:34 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*strnew;

	if ((strnew = (char *)malloc((size + 1) * sizeof(*strnew))) == NULL)
		return (NULL);
	while (size != 0)
	{
		strnew[size] = '\0';
		size--;
	}
	strnew[size] = '\0';
	return (strnew);
}
