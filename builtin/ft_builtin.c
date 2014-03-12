/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:17:28 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/11 17:26:26 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_builtin.h"

static const t_builtin	built[8] =
{
	{"cd", ft_cd},
	{"env", ft_env},
	{"setenv", ft_setenv},
	{"unsetenv", ft_unsetenv},
	{"exit", ft_exit},
	{"echo", ft_echo},
	{NULL, NULL}
};

void		ft_builtin(t_data *d, char **argv, int *i)
{
	extern t_id		g_pid;
	int				k;

	k = 0;
	while (built[k].cmd)
	{
		if (ft_strcmp(built[k].cmd, argv[0]) == 0)
		{
			g_pid.built = built[k].func(d, argv);
			*i = 1;
			return ;
		}
		k++;
	}
}
