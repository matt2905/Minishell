/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:53:48 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 14:10:39 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "minishell.h"

void	ft_exit(t_env **my_env, char **argv)
{
	ft_putendl("exit");
	free(*my_env);
	exit(ft_atoi(argv[1]));
}
