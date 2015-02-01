/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 14:49:05 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/01 20:52:58 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_builtin.h"

static void	ft_realloc_var(char **str, char *var, int index)
{
	char	*tmp;
	char	*ptr;

	ptr = ft_strchr(var, '=');
	(*str)[index - 1] = '\0';
	tmp = *str;
	*str = ft_xstrjoin("%s%s%s", tmp, ptr + 1, tmp + (ptr - var + index));
	ft_strdel(&tmp);
	ft_strdel(&var);
}

char		*ft_replace_var(t_data *d, char *str)
{
	char	*tmp;
	char	*ptr;
	char	*var;
	char	*save;

	save = ft_strdup(str);
	while ((ptr = ft_strchr(save, '$')))
	{
		tmp = ++ptr;
		while (*tmp && ft_isalnum(*tmp))
			++tmp;
		tmp = ft_strsub(ptr, 0, tmp - ptr);
		var = ft_getenv_list(d->my_env, tmp);
		if (var)
			ft_realloc_var(&save, var, ptr - save);
		ft_strdel(&tmp);
	}
	return (save);
}
