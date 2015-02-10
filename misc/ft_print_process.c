/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 12:15:21 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/10 16:21:52 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "printf.h"
#include "ft_struct.h"

static int	ft_print_exit(t_id *proc)
{
	if (WIFEXITED(proc->id) && (proc->jobs || proc->run))
	{
		ft_printf("\n[%d]\t", proc->nb);
		if (WIFEXITED(proc->id) && WEXITSTATUS(proc->id))
			ft_printf("exit %d\t\t%s\n", WEXITSTATUS(proc->id), proc->cmd);
		else if (WIFEXITED(proc->id))
			ft_printf("done\t\t%s\n", proc->cmd);
		else if (WIFSIGNALED(proc->id))
			ft_printf("%s\t%s\n", strsignal(WTERMSIG(proc->id)), proc->cmd);
		proc->run = 0;
		proc->jobs = 0;
		return (1);
	}
	return (0);
}

int			ft_print_process(t_id *proc)
{
	extern const char	*sys_siglist[];

	if (ft_print_exit(proc))
		return (1);
	if (WIFSIGNALED(proc->id))
	{
		ft_printf("42sh: %s\t%s\n", sys_siglist[WTERMSIG(proc->id)], proc->cmd);
		return (1);
	}
	if (WIFSTOPPED(proc->id))
	{
		ft_printf("\n42sh: suspended\t%s\n", proc->cmd);
		proc->run = 0;
		proc->jobs = 1;
	}
	return (0);
}
