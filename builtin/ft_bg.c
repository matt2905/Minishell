/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 18:16:24 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/10 15:57:42 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include "libft.h"
#include "printf.h"
#include "ft_minishell.h"

static void		ft_continue_child(t_id *tmp)
{
	pid_t	pid;
	int		i;

	pid = 0;
	i = 0;
	ft_printf("[%d]\tcontinued\t%s\n", tmp->nb, tmp->cmd);
	if (killpg(tmp->pid, SIGCONT) < 0)
		ft_puterror("killpg in builtin/ft_bg.c line 17: failed\n");
	tmp->run = 1;
	tmp->jobs = 0;
	while (!pid && i < 10)
	{
		usleep(10);
		i++;
		pid = waitpid (-tmp->pid, &tmp->id, WUNTRACED | WNOHANG);
	}
	if (pid)
		ft_print_process(tmp);
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
		if (tmp->jobs && !tmp->run && (tmp->nb == nb || nb == tmp->pid) &&
				(previous == -1 || previous != tmp->pid))
		{
			ft_continue_child(tmp);
			ok = 0;
		}
		previous = tmp->pid;
		tmp = tmp->next;
	}
	return (ok);
}

int				ft_bg(t_data *d, char **arg)
{
	int		i;

	i = 1;
	if (ft_tablen(arg) <= 1)
		ft_continue(d, d->nb_process - 1);
	else
	{
		while (arg[i])
		{
			if (ft_continue(d, ft_atoi(arg[i])))
			{
				ft_putstr_fd("bg: jobs not found: ", 2);
				ft_putendl_fd(arg[i], 2);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
