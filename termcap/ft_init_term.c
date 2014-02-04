/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 16:08:09 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/04 12:53:27 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "minishell.h"

void	ft_init_term(t_data *d)
{
	char	*name;

	name = ttyname(0);
	d->tty.fd = open(name, O_WRONLY);
	tcgetattr(d->tty.fd, &(d->tty.backup));
	d->tty.new_term = d->tty.backup;
	d->tty.new_term.c_lflag &= ~(ICANON | ECHO);
	d->tty.new_term.c_lflag |= ISIG;
	tcsetattr(d->tty.fd, TCSAFLUSH, &(d->tty.new_term));
}
