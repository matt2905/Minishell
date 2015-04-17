/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrlr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 10:40:59 by mmartin           #+#    #+#             */
/*   Updated: 2015/04/17 12:04:30 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termcap.h>
#include <sys/ioctl.h>
#include "libft.h"
#include "printf.h"
#include "ft_history.h"
#include "ft_minishell.h"
#include "ft_termcap.h"

static void	ft_print_search(t_history *result, char *s, t_data *d, int f)
{
	struct winsize	size;
	int				len;

	ioctl(0, TIOCGWINSZ, &size);
	ft_home(d);
	tputs(tgetstr("cd", NULL), 1, ft_int_putchar);
	if (result)
	{
		ft_strdel(&d->line->str);
		d->line->str = ft_strdup(result->line);
		d->line->len = ft_strlen(result->line);
	}
	ft_putstr_fd(d->line->str, 0);
	d->line->index = ft_strlen(d->line->str);
	len = size.ws_col - ((d->line->index + d->len_prompt) % size.ws_col);
	ft_printf("%*s%s", len, "\0", (result || f ? "" : "failing "));
	ft_printf("bck-i-search: %s_", s);
	len += (result || f ? 15 : 23);
	len += ft_strlen(s);
	while (len)
	{
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
		len--;
	}
}

static void	ft_history_up(t_data *d, t_line search, t_history **hist)
{
	static char			*str = NULL;
	static t_history	*save = NULL;

	if (!save)
		save = *hist;
	if (!search.str)
		return ;
	while (*hist && (*hist)->prev != d->history)
	{
		if (str == search.str)
			*hist = (*hist)->prev;
		if (!str || str != search.str)
			str = search.str;
		if (ft_strstr((*hist)->line, search.str))
		{
			save = *hist;
			ft_print_search(*hist, search.str, d, 0);
			return ;
		}
	}
	ft_print_search(NULL, search.str, d, 0);
	*hist = save;
}

static void	ft_delete_search(t_line *line)
{
	char	*tmp;

	if (line->len > 0)
	{
		tmp = ft_strnew(line->len);
		ft_strncpy(tmp, line->str, line->len - 1);
		ft_strdel(&line->str);
		line->str = tmp;
		line->len--;
	}
}

static void	ft_search(t_data *d, t_line *line, t_history **hist)
{
	char				*tmp;

	if (d->buff[0] == '\177')
		ft_delete_search(line);
	else
	{
		tmp = ft_strnew(line->len + 1);
		if (line->str)
			ft_strcpy(tmp, line->str);
		ft_strcat(tmp, d->buff);
		ft_strdel(&line->str);
		line->str = tmp;
		line->len++;
	}
	ft_history_up(d, *line, hist);
}

int			ft_ctrlr(t_data *d)
{
	int			ok;
	t_line		search;
	t_history	*hist;

	ok = 1;
	ft_reset_history(d);
	hist = d->first_hist;
	ft_print_search(NULL, "", d, 1);
	search.len = 0;
	search.str = NULL;
	while (ok)
	{
		ft_bzero(d->buff, 8);
		if (read(0, d->buff, 8) < 0)
			return (1);
		if (!d->buff[1] && (ft_isprint(d->buff[0]) || d->buff[0] == '\177'))
			ft_search(d, &search, &hist);
		else if (!d->buff[1] && d->buff[0] == '\022')
			ft_history_up(d, search, &hist);
		else
			ok = 0;
	}
	tputs(tgetstr("cd", NULL), 1, ft_int_putchar);
	return (0);
}
