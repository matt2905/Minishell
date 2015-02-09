/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:17:28 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/09 11:50:58 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include "ft_exec.h"
#include "ft_builtin.h"

static const t_builtin	g_built[] =
{
	{".", ft_source},
	{"alias", ft_alias},
	{"bg", ft_bg},
	{"cd", ft_cd},
	{"echo", ft_echo},
	{"env", ft_env},
	{"exit", ft_exit},
	{"fg", ft_fg},
	{"jobs", ft_jobs},
	{"setenv", ft_setenv},
	{"source", ft_source},
	{"unalias", ft_unalias},
	{"unsetenv", ft_unsetenv},
	{NULL, NULL}
};

void		ft_builtin(t_data *d, char **argv, int *i)
{
	int				k;

	k = 0;
	while (g_built[k].cmd)
	{
		if (ft_strcmp(g_built[k].cmd, argv[0]) == 0)
		{
			ft_add_process(d, d->nb_process, ft_strimplode(argv), getpid());
			d->child->built = g_built[k].func(d, argv);
			*i = 1;
			return ;
		}
		k++;
	}
}
