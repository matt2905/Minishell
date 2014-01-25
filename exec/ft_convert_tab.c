/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:24:00 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 13:37:28 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "minishell.h"

char	**ft_convert_tab(t_env **my_env)
{
	t_env	*tmp;
	char	**tab;
	int		i;

	tmp = *my_env;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = *my_env;
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tmp)
	{
		tab[i] = ft_strdup(tmp->tab);
		tmp = tmp->next;
	}
	tab[i] = NULL;
	return (tab);
}
