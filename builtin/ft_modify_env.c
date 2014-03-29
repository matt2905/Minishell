/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 12:51:22 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 20:46:36 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_minishell.h"

void	ft_modify_env(t_env **my_env, char *str, char *env)
{
	t_env	*tmp;

	tmp = *my_env;
	while (tmp && ft_strcmp(tmp->tab, env))
		tmp = tmp->next;
	if (tmp == NULL)
		return ;
	free(tmp->tab);
	tmp->tab = str;
}
