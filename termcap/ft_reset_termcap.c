/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_termcap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 17:26:52 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 12:13:10 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"

void	ft_reset_termcap(t_data *d)
{
	extern t_id		g_pid;

	tcsetattr(d->tty.fd, TCSANOW, &(d->tty.new_term));
	g_pid.father = 0;
	g_pid.built = -1;
	g_pid.id = -1;
}
