/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semunlock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 16:09:50 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/31 14:03:28 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/sem.h>
#include "libft.h"

void		ft_semunlock(int semid)
{
	struct sembuf		sops[1];

	sops[0].sem_num = 1;
	sops[0].sem_op = -1;
	sops[0].sem_flg = SEM_UNDO;
	if (semop(semid, sops, 1) == -1)
	{
		ft_putendl_fd("semop: UNLOCK failed", 2);
		exit(1);
	}
}
