/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:52:11 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/31 13:56:27 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <sys/wait.h>
#include <signal.h>
#include "libft.h"
#include "ft_minishell.h"
#include "ft_exec.h"

static void		ft_handle_signal(int sig)
{
	t_data	*d;

	d = ft_get_data(NULL);
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		ft_prompt(1);
	}
	d->signal = 1;
}

static void		ft_handle_chld(int sig)
{
	t_data	*d;
	t_id	*tmp;
	pid_t	pid;
	int		status;

	(void)sig;
	d = ft_get_data(NULL);
	tmp = d->child;
	pid = wait(&status);
	while (tmp)
	{
		if (tmp->pid == pid)
		{
			tmp->id = status;
			if (tmp->run || tmp->jobs)
				ft_print_process(d, tmp);
			tmp->run = 0;
			tmp->jobs = 0;
			d->signal = 1;
		}
		tmp = tmp->next;
	}
}

void			ft_signal(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = &ft_handle_signal;
	act.sa_flags = SA_NOCLDSTOP;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGHUP, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
	act.sa_handler = &ft_handle_chld;
	sigaction(SIGCHLD, &act, NULL);
	act.sa_handler = SIG_IGN;
	sigaction(SIGTSTP, &act, NULL);
	sigaction(SIGTTIN, &act, NULL);
	sigaction(SIGTTOU, &act, NULL);
}
