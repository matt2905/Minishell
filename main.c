/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 20:25:23 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/24 15:03:19 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <get_next_line.h>
#include <libft.h>
#include <printf.h>
#include "minishell.h"

int				main(void)
{
	char	*line;
	char	**my_env;
	int		i;
	t_lex	*lex;

	lex = NULL;
	my_env = ft_create_env(my_env);
	while (ft_prompt(my_env) && get_next_line(0, &line))
	{
		i = 0;
		ft_lexer(line, &lex);
		free(line);
/*		my_env = ft_builtin(my_env, tab, &i);
		if (i == 0)
		{
			if (ft_exec(my_env, tab) == 0)
				ft_printf("ft_minishell2: command not found: %s\n", tab[0]);
		}*/
		ft_destroy_lex(&lex);
	}
	return (0);
}
