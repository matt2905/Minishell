/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 10:32:38 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 20:46:49 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_builtin.h"

static int		ft_len_var(char *str)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

static void		ft_add_arg(t_env **new, char **argv, int i)
{
	t_env	*tmp;

	tmp = *new;
	while (tmp && ft_strncmp(tmp->tab, argv[i], ft_len_var(argv[i])))
		tmp = tmp->next;
	if (tmp)
	{
		free(tmp->tab);
		tmp->tab = ft_strdup(argv[i]);
	}
	else
		ft_add_env(new, argv[i]);
}

t_env			*ft_new_env(t_env *my_env, char **argv)
{
	t_env	*tmp;
	t_env	*new;
	int		i;

	i = 0;
	new = NULL;
	tmp = my_env;
	if (!argv[1] || argv[1][0] != '-')
	{
		while (tmp)
		{
			ft_add_env(&new, ft_strdup(tmp->tab));
			tmp = tmp->next;
		}
		while (argv[++i] && argv[i][0] != '-' && ft_strrchr(argv[i], '='))
			ft_add_arg(&new, argv, i);
	}
	return (new);
}
