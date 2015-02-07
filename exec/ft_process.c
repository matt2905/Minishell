/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 16:24:16 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/07 18:17:44 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_minishell.h"

t_id	*ft_create_process(pid_t pid, int nb, char *cmd)
{
	t_id	*new;

	new = (t_id *)malloc(sizeof(t_id));
	new->id = 0;
	new->nb = nb;
	new->built = -1;
	new->jobs = 0;
	new->run = 0;
	new->cmd = cmd;
	new->pid = pid;
	new->next = NULL;
	return (new);
}

void	ft_add_process(t_data *d, int nb, char *cmd, pid_t pid)
{
	t_id	*tmp;

	if (pid == -1)
		ft_puterror("fork() failed\n");
	if (pid)
	{
		tmp = ft_create_process(pid, nb, cmd);
		tmp->next = d->child;
		d->child = tmp;
	}
}

void	ft_delete_process(t_data *d)
{
	t_id	*tmp;
	t_id	*ptr;

	tmp = d->child;
	while (tmp)
	{
		ptr = NULL;
		if (!tmp->jobs && tmp->nb)
		{
			ptr = tmp;
			d->child = tmp->next;
		}
		else if (tmp->next && !tmp->next->jobs && tmp->next->nb)
		{
			ptr = tmp->next;
			tmp->next = ptr->next;
		}
		tmp = tmp->next;
		if (ptr)
		{
			ft_strdel(&ptr->cmd);
			free(ptr);
		}
	}
}

int		ft_check_process(t_data *d)
{
	t_id	*tmp;

	tmp = d->child;
	if (tmp->nb == 0)
		return (tmp->built);
	while (tmp)
	{
		if (tmp->nb == d->nb_process)
		{
			if (WIFSIGNALED(tmp->id) || tmp->built == 1)
				return (1);
			if (WIFEXITED(tmp->id) && WEXITSTATUS(tmp->id))
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_delete_all_process(t_data *d)
{
	t_id	*tmp;
	t_id	*ptr;

	tmp = d->child;
	while (tmp)
	{
		ptr = tmp;
		tmp = tmp->next;
		ft_strdel(&ptr->cmd);
		free(ptr);
	}
	d->child = NULL;
}
