/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 13:29:55 by mmartin           #+#    #+#             */
/*   Updated: 2014/06/17 12:46:25 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list) * content_size)) == NULL)
		return (NULL);
	new->next = NULL;
	new->content_size = 0;
	if (content == NULL)
		new->content = NULL;
	else
	{
		if ((new->content = malloc(content_size)) == NULL)
			return (new);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	return (new);
}
