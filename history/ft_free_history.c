/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 17:36:30 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/04 11:39:25 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_struct.h"

void	ft_free_history(t_history **history)
{
	t_history	*tmp;
	t_history	*ptr;

	tmp = *history;
	if (!tmp)
		return ;
	while (tmp->next != *history)
	{
		ptr = tmp;
		tmp = tmp->next;
		ptr->prev = NULL;
		ptr->next = NULL;
		ft_strdel(&ptr->line);
		free(ptr);
	}
	ft_strdel(&tmp->line);
	free(tmp);
	*history = NULL;
}
