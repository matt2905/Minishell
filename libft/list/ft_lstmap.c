/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 10:53:32 by mmartin           #+#    #+#             */
/*   Updated: 2015/01/23 16:47:47 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*begin;
	t_list		*ptr;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	begin = ft_lstnew(tmp->content, tmp->content_size);
	ptr = begin;
	if (begin)
	{
		while (lst->next)
		{
			tmp = f(lst->next);
			ptr->next = ft_lstnew(tmp->content, tmp->content_size);
			if (!ptr->next)
				return (NULL);
			ptr = ptr->next;
			lst = lst->next;
		}
	}
	return (begin);
}
