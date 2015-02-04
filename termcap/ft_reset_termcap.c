/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_termcap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 17:26:52 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/04 18:19:17 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "ft_exec.h"

void	ft_reset_termcap(t_data *d)
{
	if (d->tty.flag)
		tcsetattr(d->tty.fd, TCSANOW, &(d->tty.new_term));
	ft_delete_process(d);
	if (d->child->nb == 0)
		d->child->built = -1;
	d->nb_process--;
}
