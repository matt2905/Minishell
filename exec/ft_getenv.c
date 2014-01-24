/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 17:44:17 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/22 20:17:52 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "minishell.h"

char	*ft_getenv(char **my_env, char *var)
{
	int		i;

	i = 0;
	while (my_env && my_env[i])
	{
		if (ft_strncmp(my_env[i], var, ft_strlen(var)) == 0)
			return (my_env[i]);
		i++;
	}
	if (ft_strcmp(var, "PATH") == 0)
		return (ft_create_path());
	return (NULL);
}
