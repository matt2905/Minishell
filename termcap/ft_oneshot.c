/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oneshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 10:58:57 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/31 14:02:23 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_exec.h"

void	ft_oneshot(t_data *d)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		ft_processing(d, line);
		free(line);
	}
	exit(EXIT_SUCCESS);
}
