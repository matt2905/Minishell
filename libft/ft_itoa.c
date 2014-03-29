/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 17:01:05 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 18:04:56 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_convert(long int n, char *str, int i, int sys)
{
	str += i;
	while (i > 0)
	{
		*str = n % sys + '0';
		n /= sys;
		str--;
		i--;
	}
	*str = n % sys + '0';
}

static int	ft_len(long int n, int sys)
{
	int		j;

	j = 0;
	while (n >= sys)
	{
		n /= sys;
		j++;
	}
	return (j);
}

char		*ft_itoa(long int n, int sys)
{
	char	*str;
	int		sign;
	int		i;

	sign = 0;
	i = 0;
	if (n < 0)
	{
		n *= -1;
		sign = 1;
		i++;
	}
	i += ft_len(n, sys);
	str = ft_strnew(i + 1);
	ft_convert(n, str, i, sys);
	if (sign == 1)
		str[0] = '-';
	return (str);
}
