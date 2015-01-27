/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preg_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 10:37:01 by mmartin           #+#    #+#             */
/*   Updated: 2014/05/25 10:42:25 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_preg_replace(char *pattern, char *replacement, char *subject)
{
	char	*tmp;
	int		i;

	tmp = subject;
	while (tmp)
	{
		i = 0;
		tmp = ft_strstr(tmp, pattern);
		if (tmp)
		{
			while (replacement[i])
			{
				tmp[i] = replacement[i];
				i++;
			}
		}
	}
	return (subject);
}
