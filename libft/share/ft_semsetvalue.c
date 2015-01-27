/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semsetvalue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 16:25:24 by mmartin           #+#    #+#             */
/*   Updated: 2014/06/01 16:27:29 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/sem.h>
#include <libft.h>

void		ft_semsetvalue(int semid, int semnum, int val)
{
	union semun		u_sem;

	u_sem.val = val;
	if (semctl(semid, semnum, SETVAL, u_sem) == -1)
	{
		ft_putendl_fd("semctl: SETVAL Failed", 2);
		exit(1);
	}
}
