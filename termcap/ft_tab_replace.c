/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 11:07:58 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/30 18:18:31 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include "libft.h"
#include "ft_termcap.h"

static void	ft_print_tab(t_line *line, int len_name)
{
	int		save;
	int		len;

	save = line->index;
	len = line->len;
	ft_putstr_fd(line->str + line->index, 0);
	while (len > save + len_name)
	{
		len--;
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
	}
}

void		ft_tab_replace(t_data *d, char *str, char *name)
{
	char	*tmp;
	char	*ptr;
	int		i;

	tmp = ft_strnew(d->line->len - ft_strlen(name) + ft_strlen(str) + 1);
	ptr = d->line->str;
	i = d->line->index;
	while (i > 1 && ptr[i - 1] != '/' && !ft_isspace(ptr[i - 1]))
	{
		i--;
		tputs(tgetstr("le", NULL), 1, ft_int_putchar);
	}
	d->line->index = i;
	ft_strncpy(tmp, ptr, d->line->index);
	ft_strcat(tmp, str);
	ft_strcat(tmp, ptr + d->line->index + ft_strlen(name) + 1);
	ft_strdel(&d->line->str);
	d->line->str = tmp;
	d->line->len += ft_strlen(str) - ft_strlen(name);
	d->line->str[d->line->len] = 0;
	ft_print_tab(d->line, ft_strlen(str));
	d->line->index += ft_strlen(str);
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
