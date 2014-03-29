/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unalias.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:26:28 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/26 17:43:43 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_builtin.h"

static void		ft_print_error(char *str)
{
	ft_putstr_fd("unalias: no such element: ", 2);
	ft_putendl_fd(str, 2);
}

static int		ft_delete_alias(t_data *d, char *str)
{
	t_alias		*tmp;
	t_alias		*ptr;
	int			ret;

	tmp = d->alias;
	while (tmp && (ret = ft_strcmp(tmp->keyword, str)) < 0)
		tmp = tmp->next;
	if (!tmp || ret != 0)
	{
		ft_print_error(str);
		return (1);
	}
	if (tmp != d->alias)
	{
		ptr = d->alias;
		while (ptr->next && ft_strcmp(ptr->next->keyword, str))
			ptr = ptr->next;
		ptr->next = tmp->next;
	}
	else
		d->alias = d->alias->next;
	free(tmp->value);
	free(tmp->keyword);
	free(tmp);
	return (0);
}

int				ft_unalias(t_data *d, char **arg)
{
	int		i;

	i = 1;
	if (!arg[1])
	{
		ft_putendl_fd("unlias: not enough arguments", 2);
		return (1);
	}
	else
	{
		while (arg[i])
		{
			if ((ft_delete_alias(d, arg[i])))
				return (1);
			i++;
		}
	}
	return (0);
}
