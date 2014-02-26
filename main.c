/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 15:00:13 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/26 15:43:56 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/ioctl.h>
#include <get_next_line.h>
#include <libft.h>
#include <printf.h>
#include "ft_builtin.h"
#include "ft_termcap.h"

static void		ft_term(t_data *d)
{
	char	*line;
	char	**tab;
	int		i;

	while (ft_prompt(d) && get_next_line(0, &line))
	{
		i = 0;
		tab = ft_strsplit_space(line);
		tab = ft_tilde(tab, d);
		if (tab[0] != NULL)
		{
			ft_builtin(d, tab, &i);
			if (i == 0)
			{
				if (ft_exec(ft_convert_ltt(d->my_env), tab) == 0)
					ft_printf("42sh: command not found: %s\n", tab[0]);
			}
		}
		ft_free_tab(&tab);
		free(line);
	}
}

static void		ft_handle_signal(int sig)
{
	if (sig == SIGINT)
		ioctl(0, TIOCSTI, "\000");
}

static void		ft_signal(void)
{
	int		i;

	i = 1;
	while (i < 32)
	{
		if (i != 2)
			signal(i, SIG_IGN);
		else
			signal(i, ft_handle_signal);
		i++;
	}
}

static void		ft_init_data(t_data *d)
{
	t_env		*env;
	t_history	*history;

	env = NULL;
	history = NULL;
	d->tmp_hist = NULL;
	d->cpy = NULL;
	ft_create_env(&env);
	ft_create_history(&history);
	d->my_env = env;
	d->history = history;
	d->first_hist = ft_first_history(d->history);
	d->last_hist = ft_last_history(d->history);
}

int				main(int argc, char **argv)
{
	t_data		d;

	ft_init_data(&d);
	ft_signal();
	if (d.last_hist)
		d.last_hist->prev = d.first_hist;
	if (d.first_hist)
		d.first_hist->next = d.last_hist;
	ft_check_option(argc, argv, &d);
	if (d.tty.flag == 1)
		ft_term(&d);
	else
		ft_termcap(&d);
	return (0);
}
