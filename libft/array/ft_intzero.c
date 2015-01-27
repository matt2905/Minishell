/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 11:32:25 by mmartin           #+#    #+#             */
/*   Updated: 2014/06/04 11:44:38 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		ft_intzero(int *tab, size_t size)
{
	size_t		i;

	i = 0;
	if (!tab)
		return ;
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
}
