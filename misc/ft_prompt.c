/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:41:49 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/08 14:02:58 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_builtin.h"
#include "ft_history.h"
#include "ft_minishell.h"
#include "ft_termcap.h"

static char		*ft_get_prompt(t_data *d)
{
	char		*tmp;
	char		*prompt;

	tmp = ft_getenv_list(d->my_env, "PWD");
	if (!tmp)
		tmp = ft_getenv_list(d->my_env, "USER");
	if (!tmp)
		tmp = ft_strdup("=$42sh");
	prompt = ft_xstrjoin("\033[32m%s: \033[0m", ft_strchr(tmp, '=') + 1);
	ft_strdel(&tmp);
	d->len_prompt = ft_strlen(prompt) - 9;
	return (prompt);
}

static void		ft_reset_line(t_data *d)
{
	ft_end(d);
	ft_reset_history(d);
	ft_strdel(&d->line->str);
	d->line->index = 0;
	d->line->len = 0;
}

int				ft_prompt(int reset_line)
{
	char	*tmp;
	t_data	*d;

	d = ft_get_data(NULL);
	if (d->tty.flag && reset_line)
		ft_reset_line(d);
	tmp = ft_get_prompt(d);
	ft_putstr(tmp);
	free(tmp);
	return (1);
}
