/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:57:33 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/04 17:50:23 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "ft_exec.h"

void	ft_or(t_parser *parser, t_data *d)
{
	ft_process_tree(parser->left, d);
	if (ft_check_process(d))
		ft_process_tree(parser->right, d);
}
