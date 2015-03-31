/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 15:00:13 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/31 14:01:43 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_builtin.h"
#include "ft_exec.h"
#include "ft_history.h"
#include "ft_minishell.h"
#include "ft_termcap.h"

static void		ft_term(t_data *d)
{
	char		*line;
	int			ret;

	d->tty.fd = STDIN_FILENO;
	setpgid(0, 0);
	tcsetpgrp(d->tty.fd, getpgrp());
	ft_prompt(0);
	while ((ret = get_next_line(0, &line)) || ft_exit(d, NULL))
	{
		if (ret > 0)
		{
			ft_processing(d, line);
			ft_strdel(&line);
			ft_prompt(0);
		}
		else if (!d->signal)
			break ;
		d->signal = 0;
	}
	if (ret == 0)
		ft_exit(d, NULL);
}

static void		ft_set_manpath(t_data *d)
{
	char		**tab;
	char		*tmp;
	char		*ptr;

	tmp = getcwd(NULL, 0);
	ptr = tmp;
	tmp = ft_strjoin(tmp, "/man:/usr/local/share/man:/usr/share/man");
	free(ptr);
	tab = (char **)malloc(sizeof(char *) * 4);
	tab[0] = ft_strdup("setenv");
	tab[1] = ft_strdup("MANPATH");
	tab[2] = tmp;
	tab[3] = NULL;
	ft_setenv(d, tab);
	ft_tabdel(&tab);
}

static void		ft_save(t_data *d)
{
	char		*ptr;

	d->save_fd[0] = dup(0);
	d->save_fd[1] = dup(1);
	d->save_fd[2] = dup(2);
	d->save_pwd = ft_getenv_list(d->my_env, "PWD");
	if (d->save_pwd)
	{
		ptr = d->save_pwd;
		d->save_pwd = ft_strdup(d->save_pwd + 4);
		free(ptr);
	}
	else
		d->save_pwd = getcwd(NULL, 0);
	d->save_old = ft_getenv_list(d->my_env, "OLDPWD");
	if (d->save_old)
	{
		ptr = d->save_old;
		d->save_old = ft_strdup(d->save_old + 7);
		free(ptr);
	}
	else
		d->save_old = getcwd(NULL, 0);
}

static void		ft_init_data(t_data *d)
{
	t_env		*env;
	t_history	*history;

	env = NULL;
	history = NULL;
	d->tmp_hist = NULL;
	d->cpy = NULL;
	d->line = NULL;
	d->str = NULL;
	d->signal = 0;
	d->save_fd[0] = dup(0);
	d->save_fd[1] = dup(1);
	d->save_fd[2] = dup(2);
	d->redirect = 1;
	ft_create_env(&env);
	d->my_env = env;
	ft_levelup_shell(d);
	ft_set_manpath(d);
	ft_create_history(ft_getenv_list(d->my_env, "HOME"), &history);
	ft_save(d);
	d->history = history;
	d->first_hist = ft_first_history(d->history);
	d->last_hist = ft_last_history(d->history);
	d->ret = 0;
	ft_get_data(d);
}

int				main(int argc, char **argv)
{
	t_data		d;

	d.tty.flag = 0;
	d.fork = 0;
	d.alias = NULL;
	d.nb_process = 0;
	d.child = ft_create_process(getpid(), d.nb_process, NULL);
	ft_init_data(&d);
	ft_init_source(&d);
	ft_signal();
	if (d.last_hist)
		d.last_hist->prev = d.first_hist;
	if (d.first_hist)
		d.first_hist->next = d.last_hist;
	ft_check_option(argc, argv, &d);
	if (d.tty.flag)
		ft_termcap(&d);
	else
		ft_term(&d);
	return (0);
}
