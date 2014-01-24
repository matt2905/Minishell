/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 14:15:56 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/22 19:11:54 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_getenv_pos(char **my_env, char *var)
{
	int		i;

	i = 0;
	if (!my_env)
		return (i);
	while (my_env[i])
	{
		if (ft_strncmp(my_env[i], var, ft_strlen(var)) == 0)
			return (i);
		i++;
	}
	return (-1);
}
