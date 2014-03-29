/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:57:24 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 20:52:34 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <libft.h>
#include <printf.h>
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
		ft_printf("42sh: is a directory: %s\n", tab[0]);
		return (1);
	}
	if (access(tab[0], F_OK) == 0 && access(tab[0], R_OK) == -1)
	{
		ft_printf("42sh: permission denied: %s\n", tab[0]);
		return (1);
	}
	return (0);
}

void			ft_less(t_parser *parser, t_data *d)
{
	int				fd;
	char			**tab;

	tab = ft_strsplit_shell(parser->left->str);
	if (ft_check_error(tab))
		return ;
	if ((fd = open(tab[0], O_RDONLY)) == -1)
	{
		ft_printf("42sh: no such file or director: %s\n", tab[0]);
		return ;
	}
	ft_free_tab(&tab);
	dup2(fd, 0);
	ft_process_tree(parser->right, d);
	dup2(d->save_fd[0], 0);
	close(fd);
}
