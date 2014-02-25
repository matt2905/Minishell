/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tilde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:01:46 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/25 16:53:03 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_builtin.h"

static char		**ft_cd_empty(t_data *d, char **tab)
{
	char	*tmp;

	ft_free_tab(&tab);
	tab = (char **)malloc(sizeof(char *) * 3);
	tab[0] = ft_strdup("cd");
	tmp = ft_getenv_list(d->my_env, "HOME");
	tab[1] = ft_strdup(tmp + 5);
	free(tmp);
	tab[2] = NULL;
	return (tab);
}

char			**ft_tilde(char **tab, t_data *d)
{
	int		i;
	char	*str;
	char	*ptr;

	if ((str = ft_getenv_list(d->my_env, "HOME")) == NULL)
		return (tab);
	ptr = str;
	str = ft_strdup(str + 5);
	free(ptr);
	i = -1;
	while (tab[++i] != '\0')
	{
		if (tab[i][0] == '~')
		{
			ptr = tab[i];
			tab[i] = ft_strjoin(str, tab[i] + 1);
			free(ptr);
		}
	}
	if (!ft_strcmp(tab[0], "cd") && tab[1] == '\0')
		tab = ft_cd_empty(d, tab);
	free(str);
	return (tab);
}
