/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrlc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 18:31:22 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/25 16:58:25 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_termcap.h"

int		ft_ctrlc(t_data *d)
{
	ft_free_list(d->first);
	d->line = ft_new_char(' ');
	d->first = d->line;
	d->last = d->line;
	write(0, "\n", 1);
	ft_prompt(d);
	return (1);
}
