/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrlc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 18:31:22 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/07 16:11:52 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minishell.h"

int		ft_ctrlc(t_data *d)
{
	ft_free_list(d->first);
	d->first = NULL;
	d->line = NULL;
	d->last = NULL;
	write(0, "\n", 1);
	ft_prompt(d);
	return (1);
}
