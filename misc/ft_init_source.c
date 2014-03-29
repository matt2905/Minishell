/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_source.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 13:37:47 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 17:27:47 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "ft_builtin.h"

void		ft_init_source(t_data *d)
{
	int		fd;
	char	**tab;
	char	*tmp;
	char	*ptr;

	tmp = ft_getenv_list(d->my_env, "HOME");
	if (!tmp)
		return ;
	ptr = ft_strjoin(tmp + 5, "/.42shrc");
	fd = open(ptr, O_RDONLY);
	if (fd != -1)
	{
		tab = (char **)malloc(sizeof(char *) * 3);
		tab[0] = ft_strdup("source");
		tab[1] = ft_strdup(ptr);
		tab[2] = NULL;
		ft_source(d, tab);
		ft_free_tab(&tab);
	}
	ft_strdel(&tmp);
	ft_strdel(&ptr);
	close(fd);
}
