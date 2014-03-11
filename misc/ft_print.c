/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:55:32 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/11 17:04:34 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <printf.h>

void	ft_print_octale(char *str, int *i)
{
	char			buff[5];
	unsigned char	c;
	int				j;

	j = -1;
	while (++j < 4 && ft_isoctale(str[*i]))
	{
		buff[j] = str[*i];
		*i += 1;
	}
	*i -= 1;
	buff[j] = 0;
	c = ft_atoul(buff, 8);
	ft_printf("%c", c);
}

void	ft_print_hexa(char *str, int *i)
{
	char			buff[4];
	unsigned char	c;
	int				j;

	j = -1;
	*i += 2;
	while (++j < 2 && ft_ishexa(str[*i]))
	{
		buff[j] = str[*i];
		*i += 1;
	}
	*i -= 1;
	buff[j] = 0;
	c = ft_atoul(buff, 16);
	ft_printf("%c", c);
}
