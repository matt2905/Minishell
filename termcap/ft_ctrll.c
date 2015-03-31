/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouabou <bbouabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 16:26:10 by bbouabou          #+#    #+#             */
/*   Updated: 2015/03/31 14:38:22 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termcap.h>
#include "ft_minishell.h"
#include "ft_termcap.h"

int		ft_ctrll(t_data *d)
{
	int			pos;
	int			len;

	tputs(tgetstr("cl", NULL), 1, ft_int_putchar);
	pos = d->line->index;
	len = d->line->len;
	ft_prompt(0);
	write(0, d->line->str, len);
	while (len > pos)
	{
		len--;
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
	}
	return (1);
}
