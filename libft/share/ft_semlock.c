/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semlock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 16:03:09 by mmartin           #+#    #+#             */
/*   Updated: 2014/06/01 16:08:23 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/sem.h>
#include <libft.h>

void		ft_semlock(int semid)
{
	struct sembuf		sops[2];

	sops[0].sem_num = 0;
	sops[0].sem_op = 0;
	sops[0].sem_flg = SEM_UNDO;
	sops[1].sem_num = 1;
	sops[1].sem_op = 1;
	sops[1].sem_flg = SEM_UNDO;
	if (semop(semid, sops, 2) == -1)
	{
		ft_putendl_fd("semop: fail", 2);
		exit(1);
	}
}
