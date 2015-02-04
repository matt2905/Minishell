/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_termcap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:31:13 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/04 17:36:00 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

void		ft_backup_termcap(t_data *d)
{
	if (d->tty.flag)
		tcsetattr(d->tty.fd, TCSANOW, &(d->tty.backup));
	d->nb_process++;
}
