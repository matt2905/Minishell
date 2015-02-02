/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:52:11 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/02 19:53:41 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <signal.h>
#include "libft.h"
#include "ft_minishell.h"

static void		ft_handle_signal(int sig)
{
	extern t_id		g_pid;

	if (g_pid.father || g_pid.child)
	{
		if (g_pid.father)
			kill(sig, g_pid.father);
		else
			kill(sig, g_pid.child);
	}
	else
	{
		if (sig == SIGINT)
		{
			ft_putchar('\n');
			ft_prompt(1);
		}
		else if ((sig > 2 && sig < 17) || sig > 20)
		{
			signal(sig, SIG_DFL);
			raise(sig);
		}
		else
			signal(sig, ft_handle_signal);
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
