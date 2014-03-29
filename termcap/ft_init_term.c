/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 16:08:09 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 18:33:08 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_builtin.h"
#include "ft_termcap.h"

static void		ft_modify_termios(t_data *d)
{
	d->tty.new_term = d->tty.backup;
	d->tty.new_term.c_lflag &= ~(ICANON | ECHO);
	d->tty.new_term.c_lflag |= ISIG;
	d->tty.new_term.c_cc[VMIN] = 1;
	d->tty.new_term.c_cc[VTIME] = 0;
	d->tty.new_term.c_cc[VDSUSP] = 0;
}

void			ft_init_term(t_data *d)
{
	char	*name;
	char	*term;
	char	buff[1024];

	name = ttyname(0);
	d->tty.fd = open(name, O_WRONLY);
	free(name);
	tcgetattr(d->tty.fd, &(d->tty.backup));
	ft_modify_termios(d);
	if (tcsetattr(d->tty.fd, TCSANOW, &(d->tty.new_term)) == -1)
		ft_oneshot(d);
	d->first = NULL;
	d->last = NULL;
	d->line = NULL;
	if ((term = ft_getenv_list(d->my_env, "TERM=")) == NULL)
		exit(-1);
	if (tgetent(buff, term + 5) < 0)
	{
		free(term);
		exit(-1);
	}
	free(term);
}
