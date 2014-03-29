/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_source.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouabou <bbouabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 17:34:42 by bbouabou          #+#    #+#             */
/*   Updated: 2014/03/27 18:11:03 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "ft_exec.h"

static int		ft_error(t_data *d, char **argv, t_line *tmp, int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(": no such file or directory: ", 2);
		ft_putendl_fd(argv[1], 2);
		d->first = tmp;
	}
	else
	{
		ft_putstr_fd(argv[0], 2);
		ft_putendl_fd(": not enough arguments", 2);
	}
	return (1);
}

int				ft_source(t_data *d, char **argv)
{
	char	*str;
	int		ret;
	int		fd;
	t_line	*tmp;

	tmp = d->first;
	d->first = NULL;
	if (!argv[1])
		return (ft_error(d, argv, tmp, 0));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error(d, argv, tmp, 1));
	while ((ret = get_next_line(fd, &str)) == 1)
	{
		ft_processing(d, str);
		ft_strdel(&str);
	}
	close(fd);
	d->first = tmp;
	if (ret == -1)
		return (1);
	return (0);
}
