/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 17:15:04 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/27 13:06:46 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <libft.h>
#include "ft_termcap.h"

/*
**					Too do
**		Globing: example echo Mak* = Makefile
**		Color:	echo "\033[33m"test"" = test in yellow color
*/

static void		ft_print_echo(char **argv)
{
	int		j;

	j = 0;
	while (argv[j])
	{
		ft_putstr(argv[j]);
		j++;
	}
	ft_free_tab(&argv);
}

int				ft_echo(t_data *d, char **argv)
{
	int		i;
	int		j;

	(void)d;
	i = ft_tablen(argv);
	if (i == 1)
		ft_putchar('\n');
	else if (i == 2 && ft_strcmp(argv[1], "-n") == 0)
		ft_putchar('\0');
	else
	{
		j = (ft_strcmp(argv[1], "-n") == 0) ? 2 : 1;
		while (argv[j])
		{
			ft_print_echo(ft_strsplit(argv[j], '"'));
			j++;
			if (argv[j])
				ft_putchar(' ');
		}
		if (ft_strcmp(argv[1], "-n") != 0)
			ft_putchar('\n');
	}
	return (0);
}
