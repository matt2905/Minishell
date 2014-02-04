/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 12:26:44 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/04 19:20:19 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "minishell.h"

static t_env	*ft_new_env(char *str)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	new->next = NULL;
	new->tab = str;
	return (new);
}

void			ft_add_env(t_env **env, char *str)
{
	if (*env == NULL)
		*env = ft_new_env(str);
	else
		ft_add_env(&((*env)->next), str);
}
