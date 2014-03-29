/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 13:24:12 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 21:39:23 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include "ft_builtin.h"

char		*ft_create_path(void)
{
	int		fd;
	char	*tmp;
	char	*ptr;
	char	*line;
	int		ok;

	ok = 0;
	fd = open("/etc/paths", O_RDONLY);
	tmp = ft_strdup("PATH=");
	while (get_next_line(fd, &line))
	{
		if (ok == 1)
		{
			ptr = tmp;
			tmp = ft_strjoin(tmp, ":");
			free(ptr);
		}
		ptr = tmp;
		tmp = ft_strjoin(tmp, line);
		free(ptr);
		free(line);
		ok = 1;
	}
	return (tmp);
}

void		ft_levelup_shell(t_data *d)
{
	int		i;
	char	*tmp;
	char	**tab;

	tmp = ft_getenv_list(d->my_env, "SHLVL");
	tab = (char **)malloc(sizeof(char *) * 4);
	i = ft_atoi(tmp + 6);
	i++;
	tab[0] = ft_strdup("setenv");
	tab[1] = ft_strdup("SHLVL");
	tab[2] = ft_itoa(i, 10);
	tab[3] = NULL;
	ft_setenv(d, tab);
	ft_free_tab(&tab);
	free(tmp);
}

void		ft_create_env(t_env **env)
{
	extern char	**environ;
	int			i;
	int			flag;
	int			level;

	i = 0;
	level = 0;
	flag = 0;
	while (environ && environ[i])
	{
		ft_add_env(env, ft_strdup(environ[i]));
		if (flag == 0 && !ft_strncmp(environ[i], "PATH=", 5))
			flag = 1;
		if (level == 0 && !ft_strncmp(environ[i], "SHLVL=", 6))
			level = 1;
		i++;
	}
	if (flag == 0)
		ft_add_env(env, ft_create_path());
	if (level == 0)
		ft_add_env(env, ft_strdup("SHLVL=0"));
}
