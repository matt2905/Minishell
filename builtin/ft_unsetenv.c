/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 13:16:17 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/25 16:50:55 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_minishell.h"

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

static void	ft_deleted(t_data *d, t_env *tmp)
{
	t_env	*ptr;
	t_env	*new;

	new = d->my_env;
	if (new == tmp)
	{
		new = new->next;
		d->my_env = new;
		free(tmp);
		return ;
	}
	ptr = new;
	while (ptr->next != tmp)
		ptr = ptr->next;
	ptr->next = tmp->next;
	d->my_env = new;
	free(tmp->tab);
	free(tmp);
}

void		ft_unsetenv(t_data *d, char **argv)
{
	int		i;
	t_env	*tmp;

	i = 1;
	if (ft_error(argv) == 1)
		return ;
	while (argv[i])
	{
		tmp = d->my_env;
		while (tmp)
		{
			if (ft_strncmp(tmp->tab, argv[i], ft_strlen(argv[i])) == 0)
				ft_deleted(d, tmp);
			tmp = tmp->next;
		}
		i++;
	}
}
