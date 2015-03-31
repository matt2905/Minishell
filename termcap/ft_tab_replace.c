/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 11:07:58 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/31 16:25:12 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include "libft.h"
#include "ft_termcap.h"

static int	ft_print_tab(t_line *line)
{
	int		save;
	int		len;
	int		end;
	char	*str;

	save = line->index;
	len = line->len;
	str = line->str;
	ft_putstr_fd(line->str + line->index, 0);
	end = save;
	while (line->str[end] && (!ft_isspace(str[end])
				|| (end > 0 && ft_isspace(str[end]) && str[end - 1] == '\\')))
		end++;
	while (len > end)
	{
		len--;
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
	}
	return (end);
}

void		ft_tab_replace(t_data *d, char *str, char *name)
{
	char	*tmp;
	char	*ptr;
	int		i;

	tmp = ft_strnew(d->line->len - ft_strlen(name) + ft_strlen(str) + 1);
	ptr = d->line->str;
	i = d->line->index;
	while (i > 0 && ptr[i - 1] != '/' && !ft_isspace(ptr[i - 1]))
	{
		i--;
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
	}
	d->line->index = i;
	ft_strncpy(tmp, ptr, d->line->index);
	ft_strcat(tmp, str);
	ft_strcat(tmp, ptr + d->line->index + ft_strlen(name));
	ft_strdel(&d->line->str);
	d->line->str = tmp;
	d->line->len += ft_strlen(str) - ft_strlen(name);
	d->line->str[d->line->len] = 0;
	d->line->index = ft_print_tab(d->line);
}

int			ft_prefix_completion(t_data *d, char **tab, char *name)
{
	char	*tmp;
	int		i;
	size_t	j;
	int		ok;

	ok = 1;
	i = 1;
	j = 0;
	tmp = ft_strdup(tab[i]);
	while (ok)
	{
		if ((!tab[i][j] && tmp[j]) || (!tmp[j] && tab[i][j])
				|| tab[i][j] != tmp[j])
			ok = 0;
		i++;
		if (!tab[i] && ok)
		{
			j++;
			i = 0;
		}
	}
	tmp[j] = '\0';
	ft_tab_replace(d, tmp, name);
	ft_strdel(&tmp);
	return (j <= ft_strlen(name));
}
