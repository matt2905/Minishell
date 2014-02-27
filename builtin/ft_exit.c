/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:53:48 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/27 13:03:27 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "ft_minishell.h"

int		ft_exit(t_data *d, char **argv)
{
	ft_putendl("exit");
	tcsetattr(d->tty.fd, TCSAFLUSH, &(d->tty.backup));
	close(d->tty.fd);
	if (argv)
		exit(ft_atoi(argv[1]));
	else
		exit(0);
	return (0);
}
