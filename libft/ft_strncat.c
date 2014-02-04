/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:18:35 by mmartin           #+#    #+#             */
/*   Updated: 2013/12/06 17:29:59 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*save;

	save = s1;
	while (*save)
		save++;
	while (n != 0 && *s2 != '\0')
	{
		*save = *s2++;
		n--;
		save++;
	}
	if (*save != '\0')
		*save = '\0';
	return (s1);
}
