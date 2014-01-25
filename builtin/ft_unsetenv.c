/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 13:16:17 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 13:53:39 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "minishell.h"

static int	ft_error(char **argv)
{
	int		i;

	i = ft_tablen(argv);
	if (i < 2)
	{
		ft_putendl("Too few arguments");
		return (1);
	}
	return (0);
}

static void	ft_deleted(t_env **my_env, t_env *tmp)
{
	t_env	*ptr;

	if (*my_env == tmp)
	{
		*my_env = (*my_env)->next;
		free(tmp);
		return ;
	}
	ptr = *my_env;
	while (ptr->next != tmp)
		ptr = ptr->next;
	ptr->next = tmp->next;
	free(tmp);
}

void		ft_unsetenv(t_env **my_env, char **argv)
{
	int		i;
	t_env	*tmp;

	i = 1;
	if (ft_error(argv) == 1)
		return ;
	while (argv[i])
	{
		tmp = *my_env;
		while (tmp)
		{
			if (ft_strncmp(tmp->tab, argv[i], ft_strlen(argv[i])) == 0)
				ft_deleted(my_env, tmp);
			tmp = tmp->next;
		}
		i++;
	}
}
