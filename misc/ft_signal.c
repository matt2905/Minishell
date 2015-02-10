/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:52:11 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/10 14:14:02 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <sys/wait.h>
#include <signal.h>
#include "libft.h"
#include "printf.h"
#include "ft_minishell.h"
#include "ft_exec.h"

static int		ft_kill_child(int sig)
{
	t_id	*tmp;
	t_data	*d;
	int		ret;

	ret = 1;
	d = ft_get_data(NULL);
	tmp = d->child;
	while (tmp)
	{
		if (d->nb_process && !tmp->jobs && tmp->nb == d->nb_process)
		{
			killpg(tmp->pid, sig);
			ret = 0;
		}
		tmp = tmp->next;
	}
	return (ret);
}

static void		ft_handle_signal(int sig)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = ft_handle_signal;
	act.sa_flags = SA_NOCLDSTOP;
	if (ft_kill_child(sig))
	{
		if (sig == SIGINT)
		{
			ft_putchar('\n');
			ft_prompt(1);
		}
	}
	sigaction(sig, &act, NULL);
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
			ft_print_process(tmp);
			tmp->run = 0;
			tmp->jobs = 0;
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
	sigaction(SIGHUP, &act, NULL);
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
	act.sa_handler = &ft_handle_chld;
	sigaction(SIGCHLD, &act, NULL);
	act.sa_handler = SIG_IGN;
	sigaction(SIGTSTP, &act, NULL);
	sigaction(SIGTTIN, &act, NULL);
	sigaction(SIGTTOU, &act, NULL);
}
