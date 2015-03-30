/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preg_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 10:37:01 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/30 19:03:22 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del_one(char *tmp)
{
	int		i;

	i = 0;
	while (tmp[i + 1])
	{
		tmp[i] = tmp[i + 1];
		i++;
	}
	tmp[i] = '\0';
}

char		*ft_preg_replace(char *pattern, char *replacement, char *subject)
{
	char	*tmp;
	char	*save;
	int		i;

	save = ft_strdup(subject);
	tmp = save;
	while (tmp)
	{
		tmp = ft_strstr(tmp, pattern);
		if (tmp)
		{
			i = 0;
			while (replacement[i])
			{
				tmp[i] = replacement[i];
				i++;
			}
			if (!replacement[0])
				ft_del_one(tmp);
		}
	}
	return (save);
}
