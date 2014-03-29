/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 17:36:30 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 20:56:18 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_struct.h"

void	ft_free_history(t_history **history)
{
	t_history	*tmp;

	tmp = *history;
	while (tmp->next != *history)
	{
		tmp = tmp->next;
		free(tmp->prev->line);
		tmp->prev->prev = NULL;
		tmp->prev->next = NULL;
		free(tmp->prev);
	}
	free(tmp->line);
	free(tmp);
	*history = NULL;
}
