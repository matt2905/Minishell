/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_great.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:57:15 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/01 11:57:27 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <printf.h>
#include "ft_exec.h"

void	ft_great(t_parser *parser, t_data *d)
{
	int				fd;
	int				result;
	struct stat		buf;

	stat(parser->left->str, &buf);
	result = buf.st_mode & S_IFMT;
	if (result & S_IFDIR)
	{
		ft_printf("42sh: is a directory: %s\n", parser->left->str);
		return ;
	}
	if (access(parser->left->str, W_OK) == -1)
	{
		ft_printf("42sh: permission denied: %s\n", parser->left->str);
		return ;
	}
	fd = open(parser->left->str, O_CREAT | O_TRUNC | O_RDWR, 0644);
	dup2(fd, 1);
	ft_process_tree(parser->right, d);
	dup2(1, d->save_fd[1]);
}
