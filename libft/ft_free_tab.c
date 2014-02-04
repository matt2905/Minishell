/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 19:38:07 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/03 20:15:02 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_free_tab(char ***tab)
{
	int		i;

	i = ft_tablen(*tab);
	if (*tab)
	{
		while (i >= 0)
		{
			free((*tab)[i]);
			(*tab)[i] = NULL;
			i--;
		}
		free(*tab);
		*tab = NULL;
	}
}
