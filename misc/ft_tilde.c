/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tilde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:01:46 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/23 18:49:31 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "minishell.h"

char		**ft_tilde(char **tab, char **my_env)
{
	int		i;
	int		k;
	char	*str;
	char	*ptr;

	if ((k = ft_getenv_pos(my_env, "HOME")) == -1)
		return (tab);
	i = -1;
	while (tab[++i] != '\0')
	{
		if (tab[i][0] == '~')
		{
			str = ft_strdup(my_env[k] + 5);
			ptr = tab[i];
			tab[i] = ft_strjoin(str, tab[i] + 1);
			free(ptr);
			free(str);
		}
	}
	if (!ft_strcmp(tab[0], "cd") && tab[1] == '\0')
		tab[1] = ft_strdup(my_env[k] + 5);
	return (tab);
}
