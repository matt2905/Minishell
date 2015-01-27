/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 09:45:04 by mmartin           #+#    #+#             */
/*   Updated: 2013/12/25 21:19:07 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include "printf.h"

static int	ft_get_pad(t_printf *flags, char *str)
{
	int		len;

	if (str == NULL)
		len = 7;
	else
		len = ft_strlen(str);
	if (flags->width >= 0 && len >= flags->width)
		flags->width = 0;
	else if (flags->width >= 0)
		flags->width -= len;
	else if (flags->width < 0 && len >= flags->width * -1)
		flags->width = 0;
	else
		flags->width += len;
	if (flags->pad & 2)
		return ('0');
	else
		return (' ');
}

void		ft_printchar(char c, int *i)
{
	*i = *i + 1;
	write(1, &c, 1);
}

static void	ft_put_width(int pad, t_printf *flags, int *i)
{
	while (flags->width > 0)
	{
		ft_printchar(pad, i);
		flags->width--;
	}
}

void		ft_printstr(char *str, t_printf *flags, int *i)
{
	int		pad;

	pad = ft_get_pad(flags, str);
	if (!(flags->pad & 1))
		ft_put_width(pad, flags, i);
	if (str == NULL)
		write(1, "\0", 1);
	else
	{
		if (*flags->dot == '.')
			write(1, str, ft_strlen(str) - flags->precision);
		else
			write(1, str, ft_strlen(str));
	}
	if (flags->width < 0)
		flags->width *= -1;
	ft_put_width(' ', flags, i);
}
