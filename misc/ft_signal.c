/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:52:11 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/08 20:28:53 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <sys/wait.h>
#include <signal.h>
#include "libft.h"
#include "printf.h"
#include "ft_minishell.h"

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
	if (ft_kill_child(sig))
	{
		if (sig == SIGINT)
		{
			ft_putchar('\n');
			ft_prompt(1);
		}
	}
	signal(sig, ft_handle_signal);
}

void			ft_signal(void)
{
	signal(SIGHUP, ft_handle_signal);
	signal(SIGINT, ft_handle_signal);
	signal(SIGQUIT, ft_handle_signal);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
}
