/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 13:10:09 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/30 14:52:08 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "libft.h"
#include "printf.h"
#include "ft_termcap.h"

static void		ft_print_result(char **result, int modulo, size_t len)
{
	int			line;
	int			j;
	int			i;
	int			tablen;

	i = 0;
	tablen = ft_tablen(result);
	line = tablen / modulo + 1;
	while (i < line)
	{
		j = 0;
		ft_putchar('\n');
		while (j < modulo && i + j * line < tablen)
		{
			ft_printf("%-*s", len, result[i + j * line]);
			j++;
		}
		i++;
	}
}

void			ft_print_tab(char **result)
{
	int				i;
	struct winsize	size;
	size_t			len;
	int				j;
	int				ok;

	ioctl(0, TIOCGWINSZ, &size);
	i = 10;
	ok = 0;
	while (i > 0 && !ok)
	{
		ok = 1;
		j = 0;
		len = size.ws_col / i;
		while (ok && result[j])
		{
			if (ft_strlen(result[j]) > len - 1)
				ok = 0;
			j++;
		}
		if (!ok)
			(i)--;
	}
	ft_print_result(result, i, (i ? len : 0));
}
