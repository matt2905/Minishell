/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:43:18 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/09 18:50:24 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <get_next_line.h>
#include "minishell.h"

void	ft_create_history(t_history **history)
{
	int		fd;
	char	*line;

	fd = open("./.42sh_history", O_RDONLY);
	if (fd != -1)
	{
		while (get_next_line(fd, &line))
			ft_add_history(history, line);
	}
}
