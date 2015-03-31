/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 17:34:21 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/31 14:02:52 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "printf.h"

static void	ft_check_specbis(va_list ap, const char *str, t_printf *fl, int *i)
{
	char	*tmp;

	if (*str == 'c')
	{
		fl->precision = 1;
		tmp = ft_strnew(1);
		*tmp = va_arg(ap, int);
		if (*tmp == '\0')
		{
			ft_printchar(*tmp, i);
			if (fl->width > 0)
				fl->width -= 1;
			else if (fl->width < 0)
				fl->width += 1;
		}
		ft_printstr(tmp, fl, i);
	}
}

static void	ft_check_spec(va_list ap, const char *str, t_printf *fl, int *i)
{
	char	*ptr;
	char	*msg;

	ptr = NULL;
	msg = NULL;
	if (*str == 's')
		ft_printstr(va_arg(ap, char *), fl, i);
	else if ((*str == 'd' || *str == 'i') && (msg = fl->sign))
		ptr = ft_itoa(va_arg(ap, int), 10);
	else if (*str == 'x' && (msg = fl->sharp))
		ptr = ft_uitoa(va_arg(ap, unsigned int), 16);
	else if (*str == 'o' && (msg = fl->sharp))
		ptr = ft_uitoa(va_arg(ap, unsigned int), 8);
	else if (*str == 'u' && (msg = "\0"))
		ptr = ft_uitoa(va_arg(ap, unsigned int), 10);
	else if (*str == 'p')
	{
		*i = *i + 2;
		write(1, "0x", 2);
		ptr = ft_uitoa(va_arg(ap, unsigned long int), 16);
		ft_printstr(ptr, fl, i);
	}
	if (ptr && msg)
		ft_printnbr(ptr, fl, msg, i);
	ft_strdel(&ptr);
}

static void	ft_redirect(va_list ap, const char *str, int *i)
{
	t_printf	flags;
	int			p;

	while (*str)
	{
		flags.width = 0;
		flags.pad = 0;
		flags.precision = 0;
		flags.dot = "\0";
		if (*str == '%')
		{
			str++;
			str += ft_get_flags(str, &flags, ap);
			p = *i;
			ft_check_spec(ap, str, &flags, i);
			ft_check_specbis(ap, str, &flags, i);
			if (*str != 's' && *str != 'd' && *str != 'i' && *str != 'x'
					&& *str != 'u' && *str != 'o' && *str != 'c' && p == *i)
				ft_printchar(*str, i);
		}
		else
			ft_printchar(*str, i);
		str++;
	}
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
	ft_redirect(ap, str, &i);
	va_end(ap);
	return (i);
}
