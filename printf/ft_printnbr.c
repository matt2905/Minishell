/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 11:03:32 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 18:05:46 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

static void	ft_get_precision(t_printf *flags, char **str, int *i, char *c)
{
	int			len;
	long int	ld;

	if (ft_atoi(*str) < 0)
		c = "\0";
	while (*c)
		ft_printchar(*c++, i);
	if (**str == '-' && ((flags->pad & 2) != 0 || *flags->dot == '.'))
	{
		ft_printchar('-', i);
		ld = ft_atoi(*str);
		ld = ld * -1;
		*str = ft_itoa(ld, 10);
	}
	len = ft_strlen(*str);
	if (flags->precision < 0)
		flags->precision = 0;
	if (len >= flags->precision)
		flags->precision = 0;
	else
		flags->precision -= len;
}

static int	ft_get_pad(t_printf *fl, char **str, int *j, char *c)
{
	int		len;
	int		i;

	i = ft_strlen(fl->sign);
	len = ft_strlen(*str);
	ft_get_precision(fl, str, j, c);
	if (fl->precision < 0)
		fl->precision = 0;
	if (fl->width >= 0 && len + fl->precision + i >= fl->width)
		fl->width = 0;
	else if (fl->width >= 0)
		fl->width -= (len + fl->precision + i);
	else if (fl->width < 0 && len + fl->precision + i >= fl->width * -1)
		fl->width = 0;
	else
		fl->width += len + fl->precision + i;
	if (fl->pad & 2)
		return ('0');
	else
		return (' ');
}

static void	ft_put_width(int pad, t_printf *flags, int *i)
{
	while (flags->width > 0)
	{
		ft_printchar(pad, i);
		flags->width--;
	}
}

static void	ft_put_precision(t_printf *flags, int *i)
{
	while (flags->precision > 0)
	{
		ft_printchar('0', i);
		flags->precision--;
	}
}

void		ft_printnbr(char *str, t_printf *flags, char *c, int *i)
{
	int		pad;

	if (ft_strcmp(flags->dot, ".") == 0)
	{
		if (ft_strcmp(str, "0") == 0 && flags->precision == 0)
			*str = '\0';
		while (*c)
			ft_printchar(*c++, i);
	}
	pad = ft_get_pad(flags, &str, i, c);
	if (!(flags->pad & 1))
		ft_put_width(pad, flags, i);
	ft_put_precision(flags, i);
	while (*str)
	{
		ft_printchar(*str, i);
		str++;
	}
	if (flags->width < 0)
		flags->width *= -1;
	ft_put_width(pad, flags, i);
}
