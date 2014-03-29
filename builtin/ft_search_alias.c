/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_alias.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 16:26:51 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 12:57:51 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_builtin.h"

void			ft_free_alias(t_alias **tmp)
{
	free((*tmp)->keyword);
	(*tmp)->keyword = NULL;
	free((*tmp)->value);
	(*tmp)->value = NULL;
	free(*tmp);
	*tmp = NULL;
}

static void		ft_realloc_alias(char *value, char ***tab)
{
	char		**cmd;
	char		**tmp;
	int			len;
	int			i;
	int			j;

	tmp = ft_tabdup(*tab);
	ft_free_tab(tab);
	cmd = ft_strsplit_space(value);
	i = ft_tablen(tmp) - 1;
	j = ft_tablen(cmd);
	len = i + j;
	*tab = (char **)malloc(sizeof(char *) * (len + 1));
	(*tab)[len] = NULL;
	while (--len >= 0)
	{
		if (i > 0)
			(*tab)[len] = ft_strdup(tmp[i--]);
		else
			(*tab)[len] = ft_strdup(cmd[--j]);
	}
	ft_free_tab(&cmd);
	ft_free_tab(&tmp);
}

void			ft_search_alias(t_data *d, char ***tab)
{
	t_alias		*tmp;
	int			ret;

	tmp = d->alias;
	while (tmp && (ret = ft_strcmp(tmp->keyword, (*tab)[0])))
		tmp = tmp->next;
	if (tmp && ret == 0)
		ft_realloc_alias(tmp->value, tab);
}
