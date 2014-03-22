/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:52:11 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/19 12:09:53 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <signal.h>
#include "ft_minishell.h"

static void		ft_handle_signal(int sig)
{
	extern t_id		g_pid;

	if (g_pid.father != 0 || g_pid.child)
	{
		if (g_pid.father)
			kill(sig, g_pid.father);
		else
			kill(sig, g_pid.child);
	}
	else
	{
		if (sig == SIGINT)
			ioctl(0, TIOCSTI, "\200");
		else
			signal(sig, SIG_DFL);
	}
}

void			ft_signal(void)
{
	int		i;

	i = 1;
	while (i < 33)
	{
		signal(i, ft_handle_signal);
		i++;
	}
}
