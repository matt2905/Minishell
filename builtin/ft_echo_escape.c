/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_escape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 12:11:50 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 11:49:55 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <printf.h>
#include "ft_minishell.h"

static const t_echo		g_escape[12] =
{
	{'\\', 0, 0, 1},
	{'a', 1, '\a', 0},
	{'b', 1, '\b', 0},
	{'c', 1, 0, 0},
	{'e', 1, 0x1b, 0},
	{'f', 1, '\f', 0},
	{'n', 1, '\n', 0},
	{'r', 1, '\r', 0},
	{'t', 1, '\t', 0},
	{'\\', 1, '\\', 0},
	{'v', 1, '\v', 0},
	{0, 0, 0, 0}
};

static void				ft_print(int *back, int j, int *print, int *ok)
{
	*back = g_escape[j].newback;
	if (j != 0 && j != 12)
		ft_putchar(g_escape[j].val);
	if (j == 3)
		*ok = 0;
	*print = 1;
}

static void				ft_check(char *str, int *i, int *back)
{
	if (*back && str[*i] == '0' && ft_isdigit(str[*i + 1]))
	{
		ft_print_octale(str, i);
		*back = 0;
	}
	else if (*back && str[*i] == '0' && str[*i + 1] == 'x')
	{
		ft_print_hexa(str, i);
		*back = 0;
	}
	else if (*back)
	{
		ft_printf("\\%c", str[*i]);
		*back = 0;
	}
	else
		ft_putchar(str[*i]);
}

void					ft_putstr_echo(char *str, int *ok)
{
	int		i;
	int		j;
	int		back;
	int		print;

	back = 0;
	i = -1;
	while (*ok == 1 && str[++i])
	{
		print = 0;
		j = -1;
		while (++j < 12 && print == 0)
		{
			if (str[i] == g_escape[j].c && back == g_escape[j].back)
				ft_print(&back, j, &print, ok);
		}
		if (j == 12)
			ft_check(str, &i, &back);
	}
}
