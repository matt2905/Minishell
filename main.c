/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:03:30 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 18:36:03 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <get_next_line.h>
#include <printf.h>
#include "minishell.h"
/*
static void	ft_read_lex(t_env **my_env, t_lex *lex)
{
	t_lex	*tmp;
	int		i;

	tmp = lex;
	while (tmp)
	{
		i = 0;
		ft_builtin(my_env, tmp->tab, &i);
		if (i == 0)
		{
			if (ft_exec(ft_convert_tab(my_env), tmp->tab) == 0)
				ft_printf("42sh: command not found: %s\n", tmp->tab[0]);
		}
		tmp = tmp->next;
	}
}
*/
int			main(void)
{
	char	*line;
	t_env	*my_env;
	t_lex	*lex;
	t_pars	*pars;

	lex = NULL;
	pars = NULL;
	my_env = NULL;
	ft_create_env(&my_env);
	while (ft_prompt(&my_env) && get_next_line(0, &line))
	{
		ft_lexer(line, &lex);
		ft_parser(lex, &pars);
		free(line);
/*		ft_read_lex(&my_env, lex);
*/		ft_destroy_lex(&lex);
	}
	return (0);
}
