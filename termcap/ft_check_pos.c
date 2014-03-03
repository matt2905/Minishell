/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:08:35 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/03 11:48:00 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_minishell.h"

int		ft_check_pos(t_line *line, int len_prompt)
{
	struct winsize	size;

	ioctl(0, TIOCGWINSZ, &size);
	if ((line->pos + len_prompt) % (size.ws_col) == 0)
		return (1);
	else
		return (0);
}
