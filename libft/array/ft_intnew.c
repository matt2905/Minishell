/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 12:56:01 by mmartin           #+#    #+#             */
/*   Updated: 2015/01/27 12:54:50 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_intnew(size_t size)
{
	int			*tab;
	size_t		i;

	i = -1;
	tab = (int *)malloc(sizeof(int) * size);
	if (tab)
	{
		while (++i <= size)
			tab[i] = 0;
	}
	return (tab);
}
