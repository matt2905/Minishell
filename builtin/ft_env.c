/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:47:38 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 11:53:41 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "minishell.h"

static void	ft_error(char *str)
{
	ft_putstr_fd("ft_env: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": no such file or directory", 2);
}

void		ft_env(t_env **my_env, char **argv)
{
	int		i;
	t_env	*tmp;

	i = 0;
	while (argv[++i])
	{
		if (!ft_strchr(argv[i], '='))
		{
			ft_error(argv[i]);
			return ;
		}
	}
	tmp = *my_env;
	while (tmp)
	{
		ft_putendl(tmp->tab);
		tmp = tmp->next;
	}
	i = 0;
	while (argv[++i])
	{
		if (ft_strchr(argv[i], '='))
			ft_putendl(argv[i]);
	}
}
