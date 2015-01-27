/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 15:22:42 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/11 16:40:17 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	ft_get_char(char c, int *ok)
{
	unsigned char	tmp;

	tmp = c;
	if (ft_isdigit(c))
		tmp -= '0';
	else if (ft_isalpha(c))
		tmp -= ft_isupper(c) ? 'A' - 10 : 'a' - 10;
	else
		*ok = 0;
	return (tmp);
}

unsigned long			ft_atoul(const char *str, int base)
{
	unsigned long	res;
	unsigned char	c;
	int				ok;

	ok = 1;
	res = 0;
	if (!str)
		return (0);
	while (ft_isspace(*str))
		str++;
	while (ft_isascii(*str) && ok == 1)
	{
		c = ft_get_char(*str, &ok);
		if (c >= base)
			ok = 0;
		if (ok == 1 && c < base)
		{
			res *= base;
			res += c;
		}
		str++;
	}
	return (res);
}
