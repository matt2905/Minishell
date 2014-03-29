/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:47:38 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 20:45:31 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_builtin.h"
#include "ft_exec.h"

static void		ft_error(char *str)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": No such file or directory", 2);
}

static int		ft_exec_env(t_data *d, char **argv, int i, t_env *new_env)
{
	char	**tab;
	int		k;

	k = 0;
	tab = ft_tabdup(argv + i);
	if (tab && tab[0])
	{
		ft_builtin(d, tab, &k);
		if (k == 0)
		{
			if (ft_exec(ft_convert_ltt(new_env), tab, d->fork) == 0)
			{
				ft_error(tab[0]);
				ft_free_tab(&tab);
				return (1);
			}
		}
	}
	ft_free_tab(&tab);
	return (-1);
}

static void		ft_free_env(t_env *new)
{
	t_env	*tmp;

	while (new)
	{
		tmp = new;
		new = new->next;
		free(tmp->tab);
		free(tmp);
	}
}

static int		ft_search_option(char **argv)
{
	int		i;

	i = 0;
	while (argv && argv[++i] && argv[i][0] == '-')
	{
		if (ft_strcmp(argv[i], "--help") == 0)
		{
			ft_putstr("Usage: env [--help] [- | -i | --ignore-environ]");
			ft_putendl(" [name=value ...] [utility [argument ...]]");
			return (2);
		}
		if (ft_strcmp(argv[i], "--help") && ft_strcmp(argv[i], "-i")
				&& ft_strcmp(argv[i], "--ignore-environ") && argv[i][1] != '\0')
		{
			ft_putstr("env: illegal option -- ");
			if (argv[i][1] != '-' && argv[i][1] != 'i')
				ft_putchar(argv[i][1]);
			else
				ft_putchar(argv[i][2]);
			ft_putstr("\nUsage: env [--help] [- | -i | --ignore-environ]");
			ft_putendl(" [name=value ...] [utility [argument ...]]");
			return (1);
		}
	}
	return (0);
}

int				ft_env(t_data *d, char **argv)
{
	int		i;
	t_env	*new;
	int		ret;

	i = 0;
	if ((ret = ft_search_option(argv)) != 0)
	{
		if (ret == 2)
			ret = 0;
		return (ret);
	}
	new = ft_new_env(d->my_env, argv);
	while (argv[++i])
	{
		if (!ft_strchr(argv[i], '=') && !ft_strchr(argv[i], '-'))
			return (ft_exec_env(d, argv, i, new));
	}
	while (new)
	{
		ft_putendl(new->tab);
		new = new->next;
	}
	ft_free_env(new);
	return (0);
}
