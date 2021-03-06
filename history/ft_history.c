/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:06:15 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/31 14:01:28 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_history.h"
#include "ft_builtin.h"

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

static int		ft_open_hist(t_data *d)
{
	int		fd;
	char	*str;
	char	*ptr;

	str = ft_getenv_list(d->my_env, "HOME");
	if (!str)
		return (-1);
	ptr = str;
	str = ft_strjoin(str + 5, "/.42sh_history");
	free(ptr);
	fd = open(str, O_CREAT | O_RDWR | O_APPEND, 0644);
	free(str);
	if (fd == -1)
		return (-1);
	else
		return (fd);
}

void			ft_history(t_data *d)
{
	int			fd;
	char		*ptr;
	t_history	*hist;

	if ((fd = ft_open_hist(d)) == -1 || !d->line->len)
		return ;
	if (!(ptr = ft_strdup(d->line->str)))
		return ;
	write(fd, d->line->str, d->line->len);
	hist = d->history;
	ft_add_history(&hist, ptr);
	d->history = hist;
	ft_init_history(d);
	write(fd, "\n", 1);
	close(fd);
	ft_strdel(&ptr);
}
