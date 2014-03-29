/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:17:28 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 15:41:39 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_builtin.h"

static const t_builtin	g_built[11] =
{
	{".", ft_source},
	{"alias", ft_alias},
	{"cd", ft_cd},
	{"echo", ft_echo},
	{"env", ft_env},
	{"exit", ft_exit},
	{"setenv", ft_setenv},
	{"source", ft_source},
	{"unalias", ft_unalias},
	{"unsetenv", ft_unsetenv},
	{NULL, NULL}
};

void		ft_builtin(t_data *d, char **argv, int *i)
{
	extern t_id		g_pid;
	int				k;

	k = 0;
	while (g_built[k].cmd)
	{
		if (ft_strcmp(g_built[k].cmd, argv[0]) == 0)
		{
			g_pid.built = g_built[k].func(d, argv);
			*i = 1;
			return ;
		}
		k++;
	}
}
