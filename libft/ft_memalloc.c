/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 13:43:29 by mmartin           #+#    #+#             */
/*   Updated: 2013/12/06 17:22:02 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	char	*ptr;

	if ((ptr = (char *)malloc(size * sizeof(*ptr))) == NULL)
		return (NULL);
	while (size != 0)
	{
		ptr[size] = '\0';
		size--;
	}
	ptr[size] = '\0';
	return (ptr);
}
