/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 20:25:23 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/24 18:44:45 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <get_next_line.h>
#include <libft.h>
#include <printf.h>
#include "minishell.h"

static char		**ft_read_lex(char **my_env, t_lex *lex)
{
	t_lex	*tmp;
	int		i;

	tmp = lex;
	while (tmp)
	{
		i = 0;
		my_env = ft_builtin(my_env, tmp->tab, &i);
		if (i == 0)
		{
			if (ft_exec(my_env, tmp->tab) == 0)
				ft_printf("42sh: command not found: %s\n", tmp->tab[0]);
		}
		tmp = tmp->next;
	}
	return (my_env);
}

int				main(void)
{
	char	*line;
	char	**my_env;
	t_lex	*lex;

	lex = NULL;
	my_env = ft_create_env(my_env);
	while (ft_prompt(my_env) && get_next_line(0, &line))
	{
		ft_lexer_sep(line, &lex);
		free(line);
		my_env = ft_read_lex(my_env, lex);
		ft_destroy_lex(&lex);
	}
	return (0);
}
