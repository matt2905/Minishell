/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouabou <bbouabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 16:26:10 by bbouabou          #+#    #+#             */
/*   Updated: 2014/03/25 21:03:41 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termcap.h>
#include "ft_minishell.h"
#include "ft_termcap.h"

int		ft_ctrll(t_data *d)
{
	int			pos;
	t_line		*tmp;

	tputs(tgetstr("cl", NULL), 1, ft_int_putchar);
	pos = d->line->pos;
	tmp = d->first;
	ft_prompt(d);
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		write(0, &tmp->c, 1);
	}
	while (tmp->pos != pos)
	{
		tmp = tmp->prev;
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
	}
	return (1);
}
