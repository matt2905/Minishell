/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:41:49 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/23 15:26:18 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "minishell.h"

int		ft_prompt(char **my_env)
{
	int		k;

	ft_putstr("\033[32m");
	if ((k = ft_getenv_pos(my_env, "PWD")) != -1)
	{
		ft_putstr(ft_strrchr(my_env[k], '/'));
		ft_putstr(": ");
	}
	else if ((k = ft_getenv_pos(my_env, "USER")) != -1)
	{
		ft_putstr(my_env[k] + 5);
		ft_putstr(": ");
	}
	else
		ft_putstr("$42.sh > ");
	ft_putstr("\033[0m");
	return (1);
}
