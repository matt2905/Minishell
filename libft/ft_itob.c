/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 18:42:12 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/01 19:09:11 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_itob(unsigned int n)
{
	int				tab[15];
	int				x;
	int				i;
	unsigned int	bin;

	x = 0;
	bin = 0;
	i = 0;
	while (i < 8)
	{
		tab[x] = n % 2;
		n /= 2;
		x++;
		i++;
	}
	i = x;
	while (--i > 0)
		bin = bin + (tab[i] * ft_pow(10, i));
	return (bin);
}
