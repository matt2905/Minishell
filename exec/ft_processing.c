/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:55:15 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/31 13:58:08 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "printf.h"
#include "ft_builtin.h"
#include "ft_exec.h"
#include "ft_lexpars.h"
#include "ft_minishell.h"
#include "ft_termcap.h"

static char	*ft_clean_line(t_data *d, char *str)
{
	char	*tmp;
	char	*ptr;

	tmp = ft_replace_var(d, str);
	ptr = ft_bquote(d, tmp);
	ft_strdel(&tmp);
	tmp = ft_tilde(ptr, d);
	ft_strdel(&ptr);
	return (tmp);
}

void		ft_process(t_data *d, char **str)
{
	int				i;
	char			**tab;

	i = 0;
	tab = ft_strsplit_shell(*str);
	ft_strdel(str);
	if (tab && tab[0])
	{
		ft_search_alias(d, &tab);
		ft_builtin(d, tab, &i);
		if (i == 0)
		{
			if (ft_exec(ft_convert_ltt(d->my_env), tab, d->fork) == 0)
			{
				ft_putstr_fd("42sh: command not found: ", 2);
				ft_putendl_fd(tab[0], 2);
				d->child->built = 1;
			}
		}
	}
	ft_tabdel(&tab);
}

void		ft_processing(t_data *d, char *str)
{
	t_lexer		*lex;
	t_parser	*parser;
	char		*tmp;

	parser = NULL;
	lex = NULL;
	d->pipe = 0;
	if (!str)
		return ;
	ft_backup_termcap(d);
	tmp = ft_clean_line(d, str);
	ft_lexer(&lex, tmp);
	if (lex)
	{
		ft_strdel(&tmp);
		ft_parser(&parser, lex, 1);
		ft_free_lex(&lex);
		ft_process_tree(parser, d);
		ft_free_pars(&parser);
	}
	else
		ft_process(d, &tmp);
	ft_reset_termcap(d);
	if (d->line)
		ft_free_list(d->line, 0);
}
