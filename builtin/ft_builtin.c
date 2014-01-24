/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 14:11:26 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/23 20:55:54 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>
#include "minishell.h"

static const t_builtin	built[6] =
{
	{"cd", ft_cd},
	{"env", ft_env},
	{"setenv", ft_setenv},
	{"unsetenv", ft_unsetenv},
	{"exit", ft_exit},
	{NULL, NULL}
};

char	**ft_builtin(char **my_env, char **argv, int *i)
{
	int		k;

	k = 0;
	while (built[k].cmd)
	{
		if (ft_strcmp(built[k].cmd, argv[0]) == 0)
		{
			my_env = built[k].func(my_env, argv);
			*i = 1;
			return (my_env);
		}
		k++;
	}
	return (my_env);
}
