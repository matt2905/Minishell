/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 12:15:21 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/09 16:07:22 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "printf.h"

int		ft_print_process(int id, char *cmd)
{
	extern const char	*sys_siglist[];

	if (WIFSIGNALED(id))
	{
		ft_printf("42sh: %s\t%s\n", sys_siglist[WTERMSIG(id)], cmd);
		return (1);
	}
	return (0);
}
