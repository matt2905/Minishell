/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 17:38:27 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/30 18:07:02 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (ft_isinstring(str[i], "`\"' \t\n<>;|&~"))
			len++;
		len++;
		i++;
	}
	return (len);
}

char		*ft_escape_char(char *str)
{
	int		len;
	char	*ptr;
	char	*save;
	int		i;

	i = 0;
	len = ft_get_len(str);
	ptr = ft_strnew(len + 1);
	save = ptr;
	while (str[i])
	{
		if (ft_isinstring(str[i], "`\"' \t\n<>;|&~"))
			*save++ = '\\';
		*save++ = str[i];
		i++;
	}
	return (ptr);
}
