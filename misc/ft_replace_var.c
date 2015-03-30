/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 14:49:05 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/27 13:44:45 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_builtin.h"

static void	ft_realloc_var(char **str, char *var, int index, int ret)
{
	char	*tmp;
	char	*ptr;

	if (!ret)
		ptr = ft_strchr(var, '=');
	else
		ptr = var;
	(*str)[index - 1] = '\0';
	tmp = *str;
	if (!ret)
		*str = ft_xstrjoin("%s%s%s", tmp, ptr + 1, tmp + (ptr - var + index));
	else
		*str = ft_xstrjoin("%s%s%s", tmp, ptr, tmp + 1 + index);
	ft_strdel(&tmp);
	ft_strdel(&var);
}

static char	*ft_get_var(t_data *d, char *tmp, char *ptr, char **save)
{
	char	*var;

	while (*tmp && ft_isalnum(*tmp))
		++tmp;
	if (tmp == ptr)
		return (ptr + 1);
	tmp = ft_strsub(ptr, 0, tmp - ptr);
	var = ft_getenv_list(d->my_env, tmp);
	if (var)
	{
		ft_realloc_var(save, var, ptr - *save, 0);
		ft_strdel(&tmp);
		return (*save);
	}
	ft_strdel(&tmp);
	return (ptr + 1);
}

char		*ft_replace_var(t_data *d, char *str)
{
	char	*tmp;
	char	*ptr;
	char	*var;
	char	*save;
	char	*s;

	save = ft_strdup(str);
	s = save;
	while ((ptr = ft_strchr(s, '$')))
	{
		tmp = ++ptr;
		if (*tmp == '?')
		{
			var = ft_itoa(d->ret, 10);
			if (var)
				ft_realloc_var(&save, var, ptr - save, 1);
			s = (var ? save : ptr + 1);
		}
		else
			s = ft_get_var(d, tmp, ptr, &save);
	}
	return (save);
}
