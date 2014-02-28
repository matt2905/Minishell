/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 11:33:11 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/28 11:55:14 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lexpars.h"

void	ft_free_pars(t_parser **pars)
{
	if (*pars)
	{
		ft_free_pars(&((*pars)->left));
		ft_free_pars(&((*pars)->right));
		free((*pars)->str);
		(*pars)->left = NULL;
		(*pars)->right = NULL;
		(*pars)->type = 0;
		(*pars)->rank = 0;
		free(*pars);
	}
}
