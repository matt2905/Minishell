/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgreat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:56:51 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/07 13:12:59 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <libft.h>
#include <printf.h>
#include "ft_exec.h"

void	ft_dgreat(t_parser *parser, t_data *d)
{
	int				fd;
	int				result;
	struct stat		buf;
	char			**tab;

	tab = ft_strsplit_space(parser->left->str);
	fd = open(tab[0], O_CREAT | O_APPEND | O_RDWR, 0644);
	stat(tab[0], &buf);
	result = buf.st_mode & S_IFMT;
	if (result & S_IFDIR)
	{
		ft_printf("42sh: is a directory: %s\n", tab[0]);
		return ;
	}
	if (access(tab[0], F_OK) == 0 && access(tab[0], W_OK) == -1)
	{
		ft_printf("42sh: permission denied: %s\n", tab[0]);
		return ;
	}
	ft_free_tab(&tab);
	if (dup(1) == d->save_fd[1])
		dup2(fd, 1);
	ft_process_tree(parser->right, d);
}
