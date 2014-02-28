/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 10:42:16 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/28 18:14:08 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <printf.h>
#include "ft_builtin.h"
#include "ft_termcap.h"
#include "ft_lexpars.h"

static const t_tab	tab_func[19] =
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
	{"\200", ft_ctrlc},
	{"\013", ft_cut},
	{"\031", ft_paste},
	{NULL, ft_print}
};

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
			ret = read(0, d->buff, 8);
			d->buff[ret] = '\0';
			while (tab_func[++i].buffer != NULL && y == 0)
			{
				if (!ft_strcmp(d->buff, tab_func[i].buffer))
					y = tab_func[i].func(d);
			}
			if (tab_func[i].buffer == NULL)
				y = tab_func[i].func(d);
		}
		ft_processing(d);
	}
}
