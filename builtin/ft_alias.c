/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alias.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 15:52:16 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 13:26:53 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <printf.h>
#include "ft_builtin.h"

static int		ft_print_alias(t_data *d, char *str)
{
	t_alias		*tmp;

	tmp = d->alias;
	if (str == NULL)
	{
		while (tmp)
		{
			ft_printf("alias %s='%s'\n", tmp->keyword, tmp->value);
			tmp = tmp->next;
		}
		return (0);
	}
	else
	{
		while (tmp && ft_strcmp(tmp->keyword, str) < 0)
			tmp = tmp->next;
		if (tmp && ft_strcmp(tmp->keyword, str) == 0)
		{
			ft_printf("alias %s='%s'\n", tmp->keyword, tmp->value);
			return (0);
		}
		else
			return (1);
	}
}

static void		ft_erase_alias(t_alias **alias, t_alias *tmp, char *keyword)
{
	t_alias		*ptr;

	ptr = *alias;
	if (ptr && ft_strcmp(ptr->keyword, keyword))
	{
		while (ptr->next && ft_strcmp(ptr->next->keyword, keyword))
			ptr = ptr->next;
	}
	if (ptr == *alias)
	{
		tmp->next = ptr->next;
		ft_free_alias(&ptr);
		*alias = tmp;
	}
	else
	{
		tmp->next = ptr->next->next;
		ft_free_alias(&ptr->next);
		ptr->next = tmp;
	}
}

static void		ft_insert_alias(t_alias **alias, t_alias *tmp, char *keyword)
{
	t_alias		*ptr;
	int			ret;

	ret = -1;
	ptr = *alias;
	while (ptr->next && (ret = ft_strcmp(ptr->keyword, keyword)) < 0)
		ptr = ptr->next;
	if (ret == 0)
		ft_erase_alias(alias, tmp, keyword);
	else if (ptr == *alias)
	{
		tmp->next = ptr;
		*alias = tmp;
	}
	else
	{
		tmp->next = ptr->next;
		ptr->next = tmp;
	}
}

static void		ft_add_alias(t_alias **alias, char *keyword, char *value)
{
	t_alias		*tmp;

	tmp = (t_alias *)malloc(sizeof(t_alias));
	tmp->next = NULL;
	tmp->keyword = ft_strdup(keyword);
	tmp->value = ft_strdup(value);
	if (*alias == NULL)
		*alias = tmp;
	else
		ft_insert_alias(alias, tmp, keyword);
}

int				ft_alias(t_data *d, char **argv)
{
	t_alias		*tmp;
	char		**tab;

	if (!argv[1])
		ft_print_alias(d, NULL);
	else
	{
		tab = ft_strsplit(argv[1], '=');
		if (!tab[1])
			return (ft_print_alias(d, tab[0]));
		tmp = d->alias;
		ft_add_alias(&tmp, tab[0], tab[1]);
		d->alias = tmp;
		ft_free_tab(&tab);
	}
	return (0);
}
