/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 13:20:05 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/04 10:04:37 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell.h"

t_line			*ft_new_char(char c)
{
	t_line	*new;

	new = (t_line *)malloc(sizeof(t_line));
	new->prev = NULL;
	new->next = NULL;
	new->c = c;
	new->pos = 0;
	return (new);
}

void			ft_add_char(t_line **tmp, char c)
{
	t_line	*new;

	if (*tmp == NULL)
		*tmp = ft_new_char(c);
	else
	{
		new = ft_new_char(c);
		if ((*tmp)->next != NULL)
		{
			(*tmp)->next->prev = new;
			new->next = (*tmp)->next;
		}
		new->prev = *tmp;
		(*tmp)->next = new;
	}
}

t_line			*ft_find_first(t_line *tmp)
{
	t_line	*new;

	new = tmp;
	while (new->prev != NULL)
		new = new->prev;
	return (new);
}

t_line			*ft_find_last(t_line *first)
{
	t_line	*new;

	new = first;
	while (new && new->next != NULL)
	{
		if (new->prev)
			new->pos = new->prev->pos + 1;
		else
			new->pos = 0;
		new = new->next;
	}
	if (new->prev)
		new->pos = new->prev->pos + 1;
	else
		new->pos = 0;
	return (new);
}
