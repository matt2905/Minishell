/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 15:00:13 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/28 17:14:10 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <get_next_line.h>
#include <libft.h>
#include <printf.h>
#include "ft_builtin.h"
#include "ft_termcap.h"

t_id			gl_pid;

static void		ft_term(t_data *d)
{
	d->first = NULL;
	while (ft_prompt(d) && get_next_line(0, &d->str))
		ft_processing(d);
}

static void		ft_handle_signal(int sig)
{
	if (sig == SIGINT)
		ioctl(0, TIOCSTI, "\200");
}

static void		ft_signal(void)
{
	int		i;

	i = 1;
	while (i < 32)
		i++;
	signal(SIGINT, ft_handle_signal);
}

static void		ft_init_data(t_data *d)
{
	t_env		*env;
	t_history	*history;

	env = NULL;
	history = NULL;
	d->tmp_hist = NULL;
	d->cpy = NULL;
	ft_create_env(&env);
	d->my_env = env;
	ft_create_history(ft_getenv_list(d->my_env, "HOME"), &history);
	d->history = history;
	d->first_hist = ft_first_history(d->history);
	d->last_hist = ft_last_history(d->history);
}

int				main(int argc, char **argv)
{
	t_data		d;

	gl_pid.father = 0;
	gl_pid.id = 0;
	ft_init_data(&d);
	ft_signal();
	if (d.last_hist)
		d.last_hist->prev = d.first_hist;
	if (d.first_hist)
		d.first_hist->next = d.last_hist;
	ft_check_option(argc, argv, &d);
	if (d.tty.flag == 1)
		ft_term(&d);
	else
		ft_termcap(&d);
	return (0);
}
