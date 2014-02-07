/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 10:42:16 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/06 19:31:12 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <printf.h>
#include "minishell.h"

static const t_tab	tab_func[11] =
{
	{"\E[A", ft_go_up},
	{"\E[B", ft_go_down},
	{"\E[C", ft_go_right},
	{"\E[D", ft_go_left},
	{"\012", ft_return},
	{"\011", ft_tab},
	{"\E[3", ft_delete},
	{"\177", ft_backspace},
	{"\004", ft_exit_term},
	{"\000", ft_ctrlc},
	{NULL, ft_print}
};

void	ft_termcap_nde(t_data *d)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit_space(d->str);
	tab = ft_tilde(tab, d);
	if (tab[0] != NULL)
	{
		ft_builtin(d, tab, &i);
		if (i == 0)
		{
			if (ft_exec(ft_convert_ltt(d->my_env), tab) == 0)
				ft_printf("42sh: command not found: %s\n", tab[0]);
		}
	}
	ft_free_tab(&tab);
	free(d->str);
	ft_free_list(d->first);
	d->first = NULL;
	d->last = NULL;
	d->line = NULL;
}

void	ft_termcap(t_data *d)
{
	int		ret;
	int		i;
	int		y;

	ft_init_term(d);
	while (ft_prompt(d->my_env))
	{
		y = 0;
		d->line = ft_new_char(' ');
		while (y >= 0)
		{
			y = 0;
			i = -1;
			ret = read(0, d->buff, 6);
			d->buff[ret] = '\0';
			while (tab_func[++i].buffer != NULL && y == 0)
			{
				if (!ft_strncmp(d->buff, tab_func[i].buffer, ret))
					y = tab_func[i].func(d);
			}
			if (tab_func[i].buffer == NULL)
				y = tab_func[i].func(d);
		}
		ft_termcap_nde(d);
	}
}
