/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 12:51:04 by mmartin           #+#    #+#             */
/*   Updated: 2014/06/17 12:58:14 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;
	t_list		*ptr;

	tmp = *alst;
	while (tmp)
	{
		ptr = tmp;
		tmp = tmp->next;
		ft_lstdelone(&ptr, del);
	}
	*alst = NULL;
}
