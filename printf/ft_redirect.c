/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 14:19:14 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/26 18:51:49 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

static int	ft_get_length(const char *str, t_printf *flags, int i)
{
	int		j;

	j = 0;
	if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h')
	{
		if (str[i] == 'l')
			flags->length = "l";
		else if (str[i] == 'L')
			flags->length = "L";
		else
			flags->length = "h";
		j = 1;
	}
	return (j);
}

static int	ft_get_flags_three(const char *str, t_printf *flags)
{
	int		j;
	int		i;
	int		p;

	j = -1;
	i = 0;
	p = 0;
	while (str[++j] == '#')
		flags->sharp = "#";
	while (str[j] == '+' || str[j] == ' ')
	{
		if (str[j++] == '+')
			i = 1;
		else
			p = 2;
	}
	if (i != 0)
		flags->sign = "+";
	else if (p != 0)
		flags->sign = " ";
	return (j);
}

static int	ft_get_flags_two(const char *str, t_printf *flags)
{
	int		j;

	j = -1;
	flags->sharp = "\0";
	flags->sign = "\0";
	j += ft_get_flags_three(str, flags);
	while (str[++j] == '-' || str[j] == '0')
	{
		if (str[j] == '-')
			flags->pad = 1;
		else
			flags->pad = flags->pad | 2;
	}
	return (j);
}

int			ft_get_flags(const char *str, t_printf *flags, va_list ap)
{
	int		j;

	j = 0;
	j += ft_get_flags_two(str, flags);
	while (ft_isdigit(str[j]))
		flags->width = flags->width * 10 + str[j++] - '0';
	if (str[j] == '*')
	{
		flags->width = va_arg(ap, int);
		j++;
	}
	if (str[j] == '.')
	{
		flags->dot = ".";
		while (ft_isdigit(str[++j]))
			flags->precision = flags->precision * 10 + str[j] - '0';
		if (str[j] == '*')
		{
			flags->precision = va_arg(ap, int);
			j++;
		}
	}
	j += ft_get_length(str, flags, j);
	return (j);
}
