/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 11:21:35 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/02 09:16:48 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

static int		ft_get_len(va_list ap, const char *str)
{
	int		i;
	int		len;
	char	*tmp;

	i = -1;
	len = 0;
	while (str && str[++i])
	{
		if (str[i] == '%')
		{
			if (str[++i] == 's')
				len += ft_strlen(va_arg(ap, char *));
			else
			{
				tmp = ft_itoa(va_arg(ap, int), 10);
				len += ft_strlen(tmp);
				ft_strdel(&tmp);
			}
		}
		else
			len++;
	}
	return (len);
}

static void		ft_copy_str(char **dst, int *i, char *str)
{
	int		k;

	k = -1;
	while (str && str[++k])
	{
		(*dst)[*i] = str[k];
		*i += 1;
	}
}

static char		*ft_get_str(va_list ap, const char *str, int len)
{
	char	*dst;
	char	*tmp;
	int		i;

	i = 0;
	dst = (char *)malloc(sizeof(*dst) * (len + 1));
	while (str && *str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 's')
				ft_copy_str(&dst, &i, va_arg(ap, char *));
			else
			{
				tmp = ft_itoa(va_arg(ap, int), 10);
				ft_copy_str(&dst, &i, tmp);
				ft_strdel(&tmp);
			}
		}
		else
			dst[i++] = *str;
		str++;
	}
	return (dst);
}

char			*ft_xstrjoin(const char *str, ...)
{
	va_list		ap;
	va_list		cpy;
	char		*dst;
	int			len;

	va_start(ap, str);
	va_copy(cpy, ap);
	len = ft_get_len(cpy, str);
	va_end(cpy);
	dst = ft_get_str(ap, str, len);
	dst[len] = '\0';
	va_end(ap);
	return (dst);
}
