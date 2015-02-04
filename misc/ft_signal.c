/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:52:11 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/04 16:08:11 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <signal.h>
#include "libft.h"
#include "printf.h"
#include "ft_minishell.h"

static void		ft_handle_signal(int sig)
{
	extern t_id		g_pid;

	if (g_pid.father || g_pid.child)
	{
		if (g_pid.father)
			kill(g_pid.father, sig);
		if (g_pid.child)
			kill(g_pid.child, sig);
	}
	else
	{
		if (sig == SIGINT)
		{
			ft_putchar('\n');
			ft_prompt(1);
		}
		else
			signal(sig, ft_handle_signal);
	}
}

void			ft_signal(void)
{
	signal(SIGHUP, ft_handle_signal);
	signal(SIGINT, ft_handle_signal);
	signal(SIGQUIT, ft_handle_signal);
	signal(SIGTSTP, ft_handle_signal);
}
