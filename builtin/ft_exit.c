/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 19:06:05 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/23 20:01:05 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	**ft_exit(char **my_env, char **argv)
{
	ft_putendl("Exit");
	free(my_env);
	exit (ft_atoi(argv[1]));
	return (my_env);
}
