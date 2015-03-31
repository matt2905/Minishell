/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:57:24 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/31 13:53:38 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "libft.h"
#include "ft_exec.h"
#include "ft_minishell.h"

static int		ft_check_error(char **tab)
{
	struct stat		buff;
	int				result;

	stat(tab[0], &buff);
	result = buff.st_mode & S_IFMT;
	if (result & S_IFDIR)
	{
		ft_putstr_fd("42sh: is a directory: ", 2);
		ft_putendl_fd(tab[0], 2);
		return (1);
	}
	if (access(tab[0], F_OK) == 0 && access(tab[0], R_OK) == -1)
	{
		ft_putstr_fd("42sh: permission denied: ", 2);
		ft_putendl_fd(tab[0], 2);
		return (1);
	}
	return (0);
}

void			ft_less(t_parser *parser, t_data *d)
{
	int				fd;
	char			**tab;
	char			*tmp;

	tmp = ft_bquote(d, parser->left->str);
	tab = ft_strsplit_shell(tmp);
	ft_strdel(&tmp);
	if (ft_check_error(tab))
		return ;
	if ((fd = open(tab[0], O_RDONLY)) == -1)
	{
		ft_putstr_fd("42sh: no such file or directory: ", 2);
		ft_putendl_fd(tab[0], 2);
		return ;
	}
	ft_tabdel(&tab);
	dup2(fd, 0);
	d->redirect = 0;
	ft_process_tree(parser->right, d);
	d->redirect = 1;
	dup2(d->save_fd[0], 0);
	close(fd);
}
