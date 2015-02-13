/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 10:42:16 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/13 15:33:26 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "ft_termcap.h"
#include "ft_exec.h"
#include "ft_minishell.h"

static const t_tab	g_tab_func[] =
{
	{"\033[A", ft_go_up},
	{"\033\033[A", ft_alt_up},
	{"\033[B", ft_go_down},
	{"\033\033[B", ft_alt_down},
	{"\033[C", ft_go_right},
	{"\033\033[C", ft_alt_right},
	{"\033[D", ft_go_left},
	{"\033\033[D", ft_alt_left},
	{"\033[H", ft_home},
	{"\033[F", ft_end},
	{"\012", ft_return},
	{"\011", ft_tab},
	{"\033[3~", ft_delete},
	{"\177", ft_backspace},
	{"\004", ft_exit_term},
	{"\013", ft_cut},
	{"\031", ft_paste},
	{"\014", ft_ctrll},
	{NULL, ft_print}
};

static int		ft_init_line(t_data *d)
{
	d->str = NULL;
	if (!d->line)
	{
		d->line = (t_line *)malloc(sizeof(*d->line));
		d->line->index = 0;
		d->line->str = NULL;
		d->line->len = 0;
		d->cpy = (t_line *)malloc(sizeof(*d->line));
		d->cpy->index = 0;
		d->cpy->str = NULL;
		d->cpy->len = 0;
	}
	return (1);
}

void			ft_termcap(t_data *d)
{
	int		i;
	int		y;

	ft_init_term(d);
	while (ft_prompt(0) && ft_init_line(d))
	{
		y = 0;
		while (y >= 0)
		{
			y = 0;
			i = -1;
			ft_bzero(d->buff, 8);
			if (read(0, d->buff, 8) < 0 && !d->signal)
				return ;
			while (g_tab_func[++i].buffer != NULL && y == 0)
			{
				if (!ft_strcmp(d->buff, g_tab_func[i].buffer))
					y = g_tab_func[i].func(d);
			}
			if (g_tab_func[i].buffer == NULL)
				y = g_tab_func[i].func(d);
		}
		ft_processing(d, d->str);
		free(d->str);
	}
}
