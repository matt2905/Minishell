/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 13:34:44 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/04 17:58:02 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "minishell.h"

char	*ft_getenv_list(t_env *my_env, char *str)
{
	t_env	*tmp;

	tmp = my_env;
	while (tmp && ft_strncmp(tmp->tab, str, ft_strlen(str)))
		tmp = tmp->next;
	if (tmp)
		return (ft_strdup(tmp->tab));
	else
		return (NULL);
}
