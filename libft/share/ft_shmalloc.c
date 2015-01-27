/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 10:52:02 by mmartin           #+#    #+#             */
/*   Updated: 2014/06/01 16:40:40 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_shmalloc(key_t key, int *shmid, size_t size)
{
	void	*ptr;

	if ((*shmid = shmget(key, size, IPC_CREAT | 0644)) < 0)
	{
		ft_putendl_fd("shmget: size too large", 2);
		return (NULL);
	}
	if ((ptr = shmat(*shmid, 0, 0)) == (void *)-1)
	{
		ft_putendl_fd("shmat: id invalide", 2);
		return (NULL);
	}
	return (ptr);
}
