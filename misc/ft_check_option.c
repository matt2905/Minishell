/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 15:23:06 by mmartin           #+#    #+#             */
/*   Updated: 2015/04/13 20:37:33 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_minishell.h"

void	ft_check_option(int argc, char **argv, t_data *d)
{
	if (argc != 1)
	{
		if (ft_strncmp(argv[1], "-t", 2) == 0)
			d->tty.flag = 0;
		else
		{
			ft_putendl_fd("Usage: ./ft_minishell3 [-t]", 2);
			ft_putendl_fd("-t: desactivate termcap mode", 2);
		}
	}
}
