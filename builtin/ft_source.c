/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_source.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouabou <bbouabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 17:34:42 by bbouabou          #+#    #+#             */
/*   Updated: 2015/03/31 14:34:57 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_exec.h"

static int		ft_error(char **argv, int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(": no such file or directory: ", 2);
		ft_putendl_fd(argv[1], 2);
	}
	else
	{
		ft_putstr_fd(argv[0], 2);
		ft_putendl_fd(": not enough arguments", 2);
	}
	return (1);
}

static int		ft_ignore_com(char **str)
{
	char	*tmp;
	int		i;

	tmp = ft_strchr(*str, '#');
	if (tmp)
		tmp[0] = '\0';
	i = 0;
	while ((*str)[i])
	{
		if (!ft_isspace((*str)[i]))
			return (1);
		i++;
	}
	return (0);
}

int				ft_source(t_data *d, char **argv)
{
	char	*str;
	int		ret;
	int		fd;

	if (!argv[1])
		return (ft_error(argv, 0));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error(argv, 1));
	while ((ret = get_next_line(fd, &str)) == 1)
	{
		if (ft_ignore_com(&str))
			ft_processing(d, str);
		ft_strdel(&str);
	}
	close(fd);
	if (ret == -1)
		return (1);
	return (0);
}
