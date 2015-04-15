/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 12:29:25 by mmartin           #+#    #+#             */
/*   Updated: 2015/04/15 16:15:47 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_builtin.h"
#include "ft_minishell.h"

void		ft_puterror(char const *str)
{
	int		len;
	char	**argv;
	t_data	*d;

	argv = (char **)malloc(sizeof(*argv) * 2);
	d = ft_get_data(NULL);
	argv[0] = ft_strdup("1");
	argv[1] = NULL;
	len = ft_strlen(str);
	write(2, str, len);
	ft_exit(d, argv);
	ft_tabdel(&argv);
}
