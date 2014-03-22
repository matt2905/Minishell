/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:53:48 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/22 18:01:25 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "ft_termcap.h"

static void		ft_free_env(t_env **my_env)
{
	t_env	*tmp;
	t_env	*ptr;

	tmp = *my_env;
	while (tmp)
	{
		ptr = tmp;
		tmp = tmp->next;
		free(ptr->tab);
		free(ptr);
		ptr = NULL;
	}
}

void			ft_destroy_data(t_data *d, char **argv)
{
	if (d->str)
		free(d->str);
	ft_free_tab(&argv);
	ft_free_history(&(d->history));
	d->first_hist = NULL;
	d->last_hist = NULL;
	ft_free_env(&(d->my_env));
	ft_free_list(d->line);
}

int				ft_exit(t_data *d, char **argv)
{
	int		n;

	n = ft_atoi(argv[1]);
	ft_destroy_data(d, argv);
	ft_putendl("exit");
	if (argv)
		exit(n);
	else
		exit(0);
	return (0);
}
