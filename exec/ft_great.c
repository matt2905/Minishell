/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_great.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:57:15 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/31 13:57:57 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "libft.h"
#include "printf.h"
#include "ft_exec.h"
#include "ft_minishell.h"

static int		ft_check_error(char **tab, int fd)
{
	struct stat		buf;
	int				result;

	if (fd < 0)
	{
		ft_putstr_fd("42sh: cannot create file: ", 2);
		ft_putendl_fd(tab[0], 2);
		return (1);
	}
	stat(tab[0], &buf);
	result = buf.st_mode & S_IFMT;
	if (result & S_IFDIR)
	{
		ft_putstr_fd("42sh: is a directory: ", 2);
		ft_putendl_fd(tab[0], 2);
		return (1);
	}
	if (access(tab[0], F_OK) == 0 && access(tab[0], W_OK) == -1)
	{
		ft_putstr_fd("42sh: permission denied: ", 2);
		ft_putendl_fd(tab[0], 2);
		return (1);
	}
	return (0);
}

void			ft_great(t_parser *parser, t_data *d)
{
	int				fd;
	char			**tab;
	char			*tmp;

	tmp = ft_bquote(d, parser->left->str);
	tab = ft_strsplit_shell(tmp);
	ft_strdel(&tmp);
	fd = open(tab[0], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (ft_check_error(tab, fd))
	{
		ft_tabdel(&tab);
		return ;
	}
	ft_tabdel(&tab);
	if (d->pipe == 0)
		dup2(fd, 1);
	ft_process_tree(parser->right, d);
	if (d->pipe == 0)
		dup2(d->save_fd[1], 1);
	close(fd);
}
