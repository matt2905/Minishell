/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tilde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:01:46 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 17:30:18 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_builtin.h"

static char		*ft_realloc_tilde(char *str, int i, char *var)
{
	char	*tmp;
	char	*ptr;

	tmp = ft_strndup(str, i);
	ptr = tmp;
	tmp = ft_strjoin(tmp, var);
	free(ptr);
	ptr = str;
	str = ft_strjoin(tmp, str + i + 1);
	free(ptr);
	free(tmp);
	return (str);
}

char			*ft_tilde(char *tab, t_data *d)
{
	int		i;
	char	*str;
	char	*ptr;
	char	*tmp;

	if ((str = ft_getenv_list(d->my_env, "HOME")) == NULL)
		return (ft_strdup(tab));
	ptr = str;
	str = ft_strdup(str + 5);
	free(ptr);
	i = -1;
	tmp = ft_strdup(tab);
	while (tmp[++i])
	{
		if (tmp[i] == '~' && (i == 0 || tmp[i - 1] == ' '))
			tmp = ft_realloc_tilde(tmp, i, str);
	}
	free(str);
	return (tmp);
}
