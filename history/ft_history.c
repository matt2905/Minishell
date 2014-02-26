/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:06:15 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/26 18:05:23 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_minishell.h"

t_history		*ft_last_history(t_history *hist)
{
	t_history	*last;

	last = hist;
	while (last && last->prev)
		last = last->prev;
	return (last);
}

t_history		*ft_first_history(t_history *hist)
{
	t_history	*first;

	first = hist;
	while (first && first->next)
		first = first->next;
	return (first);
}

static void		ft_init_history(t_data *d)
{
	if (d->history && d->history->next)
		d->history = d->history->next;
	if (d->last_hist == NULL)
		d->last_hist = ft_last_history(d->history);
	d->first_hist = ft_first_history(d->history);
	d->last_hist->prev = d->first_hist;
	d->first_hist->next = d->last_hist;
}

void			ft_history(t_data *d)
{
	int			fd;
	t_line		*tmp;
	char		*ptr;
	int			i;
	t_history	*hist;

	tmp = d->first;
	if ((fd = open("./.42sh_history", O_CREAT | O_RDWR | O_APPEND, 0644)) == -1)
		return ;
	if (!d->last->prev)
		return ;
	ptr = (char *)malloc(sizeof(char) * (d->last->prev->pos + 2));
	i = 0;
	while ((tmp = tmp->next))
	{
		write(fd, &tmp->c, 1);
		ptr[i++] = tmp->c;
	}
	ptr[i] = '\0';
	hist = d->history;
	ft_add_history(&hist, ptr);
	d->history = hist;
	ft_init_history(d);
	write(fd, "\n", 1);
	close(fd);
}
