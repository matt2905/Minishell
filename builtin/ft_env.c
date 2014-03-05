/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:47:38 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/05 10:35:46 by mmartin          ###   ########.fr       */
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

int				ft_exec_env(t_data *d, char **argv, int i, t_env *new_env)
{
	char	**tab;
	int		k;

	k = 0;
	tab = ft_tabdup(argv + i);
	if (tab && tab[0])
	{
		tab = ft_tilde(tab, d);
		ft_builtin(d, tab, &k);
		if (k == 0)
		{
			if (ft_exec(ft_convert_ltt(new_env), tab) == 0)
			{
				ft_error(tab[0]);
				ft_free_tab(&tab);
				return (1);
			}
		}
	}
	ft_free_tab(&tab);
	return (0);
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

int				ft_env(t_data *d, char **argv)
{
	int		i;
	t_env	*new;

	i = 0;
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
