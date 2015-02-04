/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:52:11 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/04 17:23:20 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <signal.h>
#include "libft.h"
#include "printf.h"
#include "ft_minishell.h"

static void		ft_handle_signal(int sig)
{
	t_data	*d;

	d = ft_get_data(NULL);
	if (d->child->pid)
		kill(d->child->pid, sig);
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
