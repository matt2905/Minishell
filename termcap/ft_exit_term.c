/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 18:19:12 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/15 11:57:26 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "ft_builtin.h"
#include "ft_termcap.h"

int		ft_exit_term(t_data *d)
{
	ft_end(d);
	write(0, "\n", 1);
	ft_exit(d, NULL);
	return (1);
}
