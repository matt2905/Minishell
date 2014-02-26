/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oneshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 10:58:57 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/26 11:32:12 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <get_next_line.h>
#include <libft.h>
#include <printf.h>
#include "ft_builtin.h"

void	ft_oneshot(t_data *d)
{
	char	*line;
	char	**tab;
	int		i;

	i = 0;
	get_next_line(0, &line);
	tab = ft_strsplit_space(line);
	if (tab && tab[0])
	{
		tab = ft_tilde(tab, d);
		ft_builtin(d, tab, &i);
		if (i == 0)
		{
			if (ft_exec(ft_convert_ltt(d->my_env), tab) == 0)
				ft_printf("42sh: command not found: %s\n", tab[0]);
		}
	}
	ft_free_tab(&tab);
	free(line);
	exit(EXIT_SUCCESS);
}
