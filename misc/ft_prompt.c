/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:41:49 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 13:42:20 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "minishell.h"

int		ft_prompt(t_env **my_env)
{
	char	*tmp;

	ft_putstr("\033[32m");
	if ((tmp = ft_getenv_list(my_env, "PWD")) != NULL)
	{
		ft_putstr(ft_strrchr(tmp, '/'));
		ft_putstr(": ");
	}
	else if ((tmp = ft_getenv_list(my_env, "USER")) != NULL)
	{
		ft_putstr(tmp + 5);
		ft_putstr(": ");
	}
	else
		ft_putstr("$42.sh > ");
	ft_putstr("\033[0m");
	return (1);
}
