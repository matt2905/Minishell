/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:08:35 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/28 15:14:54 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_minishell.h"

int		ft_check_pos(t_data *d)
{
	struct winsize	size;

	ioctl(0, TIOCGWINSZ, &size);
	if ((d->line->pos + d->len_prompt) % (size.ws_col) == 0)
		return (1);
	else
		return (0);
}
