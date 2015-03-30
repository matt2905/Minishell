/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 11:05:25 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/30 17:54:39 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <dirent.h>
#include "libft.h"
#include "ft_termcap.h"
#include "ft_minishell.h"

static char		*ft_search_path(char *str, int i)
{
	int		end;
	char	*path;
	char	*tmp;

	if (!str || !*str)
		return (NULL);
	path = NULL;
	while (!ft_isspace(str[i]) && i > 0)
		i--;
	end = ++i;
	while (str[end] && !ft_isspace(str[end]))
		end++;
	if (str[i] == '/')
	{
		path = ft_strnrchr(str + i, '/', end - i);
		path = ft_strndup(str + i, path - (str + i) + 1);
	}
	else
	{
		path = ft_strnrchr(str + i, '/', end - i);
		tmp = ft_strndup(str + i, path - (str + i) + 1);
		path = ft_strjoin("./", path ? tmp : "");
		ft_strdel(&tmp);
	}
	return (path);
}

static char		*ft_get_name(char *str, int i)
{
	char	*name;
	char	*tmp;
	int		end;

	name = NULL;
	while (!ft_isspace(str[i]) && i > 0)
		i--;
	end = ++i;
	while (str[end] && !ft_isspace(str[end]))
		end++;
	tmp = ft_strnrchr(str + i, '/', end - i);
	if (!tmp)
		name = ft_strndup(str + i, end - i);
	else
	{
		i = tmp - str;
		name = ft_strndup(str + i + 1, end - i);
	}
	return (name);
}

static char		**ft_search_files(DIR *dirp, char *name)
{
	struct dirent	*file;
	char			**result;
	int				i;
	char			*dir;
	char			*tmp;

	dir = NULL;
	result = NULL;
	i = 1;
	while ((file = readdir(dirp)))
	{
		if ((!name || !ft_strncmp(name, file->d_name, ft_strlen(name))) &&
				ft_strcmp(file->d_name, ".") && ft_strcmp(file->d_name, ".."))
		{
			dir = ft_strjoin(file->d_name, (file->d_type == DT_DIR ? "/" : ""));
			tmp = ft_escape_char(dir);
			ft_strdel(&dir);
			result = ft_tabrealloc(&result, tmp, i);
			ft_strdel(&tmp);
			i++;
		}
	}
	return (result);
}

static void		ft_completion(t_data *d, char **result, char *name)
{
	int		save;

	if (ft_tablen(result) == 1)
		ft_tab_replace(d, result[0], name);
	else
	{
		if (ft_prefix_completion(d, result, name))
		{
			save = d->line->len;
			ft_print_tab(result);
			ft_putchar('\n');
			ft_prompt(0);
			ft_putstr(d->line->str);
			while (save > d->line->index)
			{
				tputs(tgetstr("le", NULL), 1, ft_int_putchar);
				save--;
			}
		}
	}
}

int				ft_tab(t_data *d)
{
	char			*path;
	DIR				*dirp;
	char			**result;
	char			*name;

	if (!(path = ft_search_path(d->line->str, d->line->index)))
		return (1);
	if (!(dirp = opendir(path)))
	{
		ft_strdel(&path);
		return (1);
	}
	name = ft_get_name(d->line->str, d->line->index);
	result = ft_search_files(dirp, name);
	ft_bubble_sort_str(result);
	if (result)
		ft_completion(d, result, name);
	closedir(dirp);
	ft_strdel(&path);
	ft_strdel(&name);
	ft_tabdel(&result);
	return (1);
}
