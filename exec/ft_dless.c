/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dless.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:57:03 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/11 14:45:27 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "ft_exec.h"
#include "ft_minishell.h"

static void		ft_heredoc(char **tab)
{
	char	*line;
	int		fd;
	int		ok;
	int		ret;

	ok = 0;
	ret = 1;
	fd = open("/tmp/.less", O_WRONLY | O_TRUNC | O_CREAT, 0666);
	while (!ok)
	{
		if (ret)
			ft_putstr("heredoc> ");
		if ((ret = get_next_line(0, &line)) < 0)
			return ;
		if (ret)
		{
			if (!ft_strcmp(line, tab[0]))
				ok = 1;
			else
				ft_putendl_fd(line, fd);
			ft_strdel(&line);
		}
	}
	close(fd);
}

void			ft_dless(t_parser *parser, t_data *d)
{
	char	**tab;
	int		fd;

	tab = ft_strsplit_shell(parser->left->str);
	if (!tab || !tab[0])
	{
		ft_putendl_fd("parser error", 2);
		return ;
	}
	ft_heredoc(tab);
	ft_tabdel(&tab);
	fd = open("/tmp/.less", O_RDONLY);
	dup2(fd, 0);
	ft_process_tree(parser->right, d);
	dup2(d->save_fd[0], 0);
	close(fd);
}
