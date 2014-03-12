/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:55:15 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/12 15:04:40 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <printf.h>
#include "ft_builtin.h"
#include "ft_exec.h"
#include "ft_termcap.h"

void		ft_process(t_data *d, char *str)
{
	int		i;
	char	**tab;
	char	*tmp;

	i = 0;
	tmp = ft_tilde(str, d);
	tab = ft_strsplit_shell(tmp);
	free(tmp);
	if (tab && tab[0])
	{
		ft_builtin(d, tab, &i);
		if (i == 0)
		{
			if (ft_exec(ft_convert_ltt(d->my_env), tab, d->fork) == 0)
				ft_printf("42sh: command not found: %s\n", tab[0]);
		}
		ft_reset_termcap(d);
	}
	ft_free_tab(&tab);
}

void		ft_processing(t_data *d)
{
	t_lexer		*lex;
	t_parser	*parser;

	parser = NULL;
	lex = NULL;
	d->pipe = 0;
	ft_lexer(&lex, d->str);
	if (lex)
	{
		ft_parser(&parser, lex, 1);
		ft_free_lex(&lex);
		ft_process_tree(parser, d);
		ft_free_pars(&parser);
	}
	else
		ft_process(d, d->str);
	if (d->str)
		free(d->str);
	if (d->first)
		ft_free_list(d->first);
}
