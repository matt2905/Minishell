/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:43:18 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 21:39:38 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include "ft_history.h"

void	ft_create_history(char *ptr, t_history **history)
{
	int		fd;
	char	*line;
	char	*str;

	if (ptr)
	{
		str = ft_strjoin(ptr + 5, "/.42sh_history");
		free(ptr);
		fd = open(str, O_RDONLY);
		free(str);
		if (fd != -1)
		{
			while (get_next_line(fd, &line))
				ft_add_history(history, line);
		}
	}
}
