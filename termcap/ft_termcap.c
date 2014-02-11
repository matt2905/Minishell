/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 10:42:16 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/09 15:47:08 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <printf.h>
#include "minishell.h"

static const t_tab	tab_func[17] =
{
	{"\E[A", ft_go_up},
	{"\E\E[A", ft_alt_up},
	{"\E[B", ft_go_down},
	{"\E\E[B", ft_alt_down},
	{"\E[C", ft_go_right},
	{"\E\E[C", ft_alt_right},
	{"\E[D", ft_go_left},
	{"\E\E[D", ft_alt_left},
	{"\E[H", ft_home},
	{"\E[F", ft_end},
	{"\012", ft_return},
	{"\011", ft_tab},
	{"\E[3~", ft_delete},
	{"\177", ft_backspace},
	{"\004", ft_exit_term},
	{"\000", ft_ctrlc},
	{NULL, ft_print}
};

static void		ft_termcap_nde(t_data *d)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit_space(d->str);
	if (tab && tab[0] != NULL)
	{
		tab = ft_tilde(tab, d);
		ft_builtin(d, tab, &i);
		if (i == 0)
		{
			if (ft_exec(ft_convert_ltt(d->my_env), tab) == 0)
				ft_printf("42sh: command not found: %s\n", tab[0]);
		}
	}
	ft_free_tab(&tab);
	if (d->str)
		free(d->str);
	ft_free_list(d->first);
}

static int		ft_init_line(t_data *d)
{
	d->line = ft_new_char(' ');
	d->first = d->line;
	d->last = d->line;
	return (1);
}

void			ft_termcap(t_data *d)
{
	int		ret;
	int		i;
	int		y;

	ft_init_term(d);
	while (ft_prompt(d) && ft_init_line(d))
	{
		y = 0;
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
