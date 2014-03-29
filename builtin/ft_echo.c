/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 17:15:04 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 20:44:52 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_builtin.h"

static int		ft_print_echo(char *argv, int el, int eu)
{
	int		ok;

	ok = 1;
	if (eu == 1 && el == 0)
		ft_putstr(argv);
	else
	{
		ft_putstr_echo(argv, &ok);
		if (ok == 0)
			return (0);
	}
	return (1);
}

static int		ft_get_option(char **argv, int *n, int *el, int *eu)
{
	int		i;

	i = 1;
	*n = 0;
	*el = 0;
	*eu = 0;
	while (argv[i] && argv[i][0] == '-')
	{
		if (argv[i][1] == 'e')
			*el = 1;
		else if (argv[i][1] == 'E')
			*eu = 1;
		else if (argv[i][1] == 'n')
			*n = 1;
		else
			return (i);
		i++;
	}
	return (i);
}

int				ft_echo(t_data *d, char **argv)
{
	int		j;
	int		n;
	int		el;
	int		eu;
	int		ok;

	(void)d;
	j = ft_get_option(argv, &n, &el, &eu);
	while (argv[j])
	{
		ok = ft_print_echo(argv[j], el, eu);
		if (ok == 0)
			return (0);
		j++;
		if (argv[j])
			ft_putchar(' ');
	}
	if (n == 0)
		ft_putchar('\n');
	return (0);
}
