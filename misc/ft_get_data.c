/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 12:40:32 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/01 12:47:16 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_struct.h"

t_data		*ft_get_data(t_data *d)
{
	static	t_data	*data = NULL;

	if (!data && d)
		data = d;
	return (data);
}
