/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:00:09 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 18:57:54 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

static t_param	*ft_new_param(char *str)
{
	t_param		*new;

	new = (t_param *)malloc(sizeof(t_param));
	new->next = NULL;
	new->str = str;
	return (new);
}

void			ft_add_param(t_param **param, char *str)
{
	if (*param == NULL)
		*param = ft_new_param(str);
	else
		ft_add_param(&((*param)->next), str);
}

static t_pars	*ft_new_node(char *str)
{
	t_pars		*new;

	new = (t_pars *)malloc(sizeof(t_pars));
	new->left = NULL;
	new->right = NULL;
	new->token = str;
	new->param = ft_new_param(str);
	return (new);
}

void			ft_add_node(t_pars **pars, char *str)
{
	if (*pars == NULL)
		*pars = ft_new_node(str);
}
