/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oneshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 10:58:57 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/22 10:50:15 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <get_next_line.h>
#include "ft_builtin.h"
#include "ft_exec.h"

void	ft_oneshot(t_data *d)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		ft_processing(d);
		free(line);
	}
	exit(EXIT_SUCCESS);
}
