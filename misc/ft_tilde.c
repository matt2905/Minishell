/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tilde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:01:46 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 13:39:40 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "minishell.h"

char		**ft_tilde(char **tab, t_env **my_env)
{
	int		i;
	char	*str;
	char	*ptr;

	if ((str = ft_getenv_list(my_env, "HOME")) == NULL)
		return (tab);
	i = -1;
	while (tab[++i] != '\0')
	{
		if (tab[i][0] == '~')
		{
			str = ft_strdup(str + 5);
			ptr = tab[i];
			tab[i] = ft_strjoin(str, tab[i] + 1);
			free(ptr);
			free(str);
		}
	}
	if (!ft_strcmp(tab[0], "cd") && tab[1] == '\0')
		tab[1] = ft_strdup(ft_getenv_list(my_env, "HOME") + 5);
	return (tab);
}
