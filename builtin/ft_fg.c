/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 11:04:09 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/19 09:02:44 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include "libft.h"
#include "printf.h"
#include "ft_minishell.h"

static void		ft_continue_child(t_data *d, t_id *tmp)
{
	ft_printf("[%d]\tcontinued\t%s\n", tmp->nb, tmp->cmd);
	if (tcsetpgrp(d->tty.fd, getpgid(tmp->pid)) < 0)
		ft_puterror("tcsetpgrp in builtin/ft_fg.c line 23: failed\n");
	if (!tmp->run && killpg(tmp->pid, SIGCONT) < 0)
		ft_puterror("kill in builtin/ft_fg.c line 25: failed\n");
	tmp->jobs = 0;
	tmp->run = 0;
	waitpid(-tmp->pid, &tmp->id, WUNTRACED);
	ft_print_process(d, tmp);
	if (tcsetpgrp(d->tty.fd, getpgrp()) < 0)
		ft_puterror("tcsetpgrp in builtin/ft_fg.c line 30: failed\n");
}

static int		ft_continue(t_data *d, int nb)
{
	t_id		*tmp;
	pid_t		previous;
	int			ok;

	previous = -1;
	ok = 1;
	tmp = d->child;
	while (tmp)
	{
		if ((tmp->jobs || tmp->run) && (tmp->nb == nb || nb == tmp->pid) &&
				(previous == -1 || previous != tmp->pid))
		{
			ft_continue_child(d, tmp);
			ok = 0;
		}
		previous = tmp->pid;
		tmp = tmp->next;
	}
	return (ok);
}

int				ft_fg(t_data *d, char **arg)
{
	int		i;

	i = 1;
	if (ft_tablen(arg) <= 1)
		return (ft_continue(d, d->nb_process - 1));
	else
	{
		while (arg[i])
		{
			if (ft_continue(d, ft_atoi(arg[i])))
			{
				ft_putstr_fd("fg: job not found: ", 2);
				ft_putendl_fd(arg[i], 2);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
