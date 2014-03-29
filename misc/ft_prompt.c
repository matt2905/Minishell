/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:41:49 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 21:01:07 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_builtin.h"

int		ft_prompt(t_data *d)
{
	char	*tmp;
	int		len;

	ft_putstr("\033[32m");
	len = ft_strlen("$42.sh > ");
	if ((tmp = ft_getenv_list(d->my_env, "PWD")) != NULL)
	{
		len = ft_strlen(ft_strrchr(tmp, '/')) + 2;
		ft_putstr(ft_strrchr(tmp, '/'));
		ft_putstr(": ");
	}
	else if ((tmp = ft_getenv_list(d->my_env, "USER")) != NULL)
	{
		len = ft_strlen(tmp + 5) + 2;
		ft_putstr(tmp + 5);
		ft_putstr(": ");
	}
	else
		ft_putstr("$42.sh > ");
	ft_putstr("\033[0m");
	d->len_prompt = len;
	free(tmp);
	return (1);
}
