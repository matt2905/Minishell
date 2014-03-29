/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ltt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:27:08 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 20:49:09 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_struct.h"

char	**ft_convert_ltt(t_env *my_env)
{
	t_env	*tmp;
	char	**tab;
	int		i;

	tmp = my_env;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = my_env;
	if ((tab = (char **)malloc(sizeof(char *) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (tmp)
	{
		tab[i++] = ft_strdup(tmp->tab);
		tmp = tmp->next;
	}
	tab[i] = NULL;
	return (tab);
}
