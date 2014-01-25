/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 16:59:55 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 18:36:54 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parser(t_lex *lex, t_pars **pars)
{
	t_lex	*tmp;

	tmp = lex;
	while (tmp)
	{
		ft_add_node(pars, tmp->token);
		tmp = tmp->next;
	}
}
