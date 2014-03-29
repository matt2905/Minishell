/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oneshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 10:58:57 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 21:38:05 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_exec.h"

void	ft_oneshot(t_data *d)
{
	char	*line;

	d->first = NULL;
	while (get_next_line(0, &line))
	{
		ft_processing(d, line);
		free(line);
	}
	exit(EXIT_SUCCESS);
}
