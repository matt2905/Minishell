/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:45:41 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 20:55:25 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell.h"

static t_history	*ft_new_history(char *line)
{
	t_history	*new;

	new = (t_history *)malloc(sizeof(t_history));
	new->prev = NULL;
	new->next = NULL;
	new->line = line;
	new->flag = 0;
	return (new);
}

void				ft_add_history(t_history **history, char *line)
{
	if (*history == NULL)
		*history = ft_new_history(line);
	else
	{
		(*history)->next = ft_new_history(line);
		(*history)->next->prev = *history;
		*history = (*history)->next;
	}
}
