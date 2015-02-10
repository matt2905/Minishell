/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:53:48 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/10 17:57:40 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_termcap.h"
#include "ft_history.h"
#include "ft_exec.h"
#include "ft_minishell.h"

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

static void		ft_free_alias(t_alias *alias)
{
	t_alias		*tmp;
	t_alias		*ptr;

	tmp = alias;
	while (tmp)
	{
		ptr = tmp;
		tmp = tmp->next;
		free(ptr->keyword);
		free(ptr->value);
		free(ptr);
	}
}

void			ft_destroy_data(t_data *d, char **argv)
{
	if (d->str)
		free(d->str);
	ft_tabdel(&argv);
	ft_free_history(&(d->history));
	d->first_hist = NULL;
	d->last_hist = NULL;
	ft_free_env(&(d->my_env));
	ft_free_alias(d->alias);
	ft_free_list(d->line, 1);
	ft_free_list(d->cpy, 1);
	free(d->save_pwd);
	free(d->save_old);
	ft_delete_all_process(d);
}

int				ft_exit(t_data *d, char **argv)
{
	int		n;

	if (argv)
		n = ft_atoi(argv[1]);
	else
		n = 0;
	if (d->child && d->child->next)
	{
		ft_putendl_fd("\n42sh: you have suspended jobs.", 2);
		ft_prompt(0);
		return (1);
	}
	if (d->tty.flag)
		tcsetattr(d->tty.fd, TCSANOW, &(d->tty.backup));
	ft_destroy_data(d, argv);
	ft_putendl("exit");
	exit(n);
	return (0);
}
