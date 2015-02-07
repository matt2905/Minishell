/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bquote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 13:46:13 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/07 21:09:15 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_exec.h"
#include "ft_lexpars.h"
#include "libft.h"

static void	ft_child(t_data *d, char *str, int *fd_pipe)
{
	t_lexer		*lex;
	t_parser	*pars;

	lex = NULL;
	pars = NULL;
	close(fd_pipe[0]);
	dup2(fd_pipe[1], 1);
	ft_lexer(&lex, str);
	if (lex)
	{
		ft_parser(&pars, lex, 1);
		ft_free_lex(&lex);
		ft_process_tree(pars, d);
		ft_free_pars(&pars);
	}
	else
		ft_process(d, str);
	exit(EXIT_SUCCESS);
}

static void	ft_realloc_bquote(int fd, char **save)
{
	char		*line;
	char		*ptr;
	char		*str;
	char		*tmp;
	char		*del;

	tmp = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ptr = tmp;
		tmp = ft_xstrjoin("%s %s", tmp, line);
		ft_strdel(&ptr);
		ft_strdel(&line);
	}
	ptr = ft_strchr(*save, '`');
	(*save)[ptr - *save] = '\0';
	str = ft_strchr(++ptr, '`');
	del = tmp;
	tmp = ft_strtrim(tmp);
	ft_strdel(&del);
	del = *save;
	*save = ft_xstrjoin("%s%s%s", *save, tmp, *save + (++str - *save));
	ft_strdel(&del);
	ft_strdel(&tmp);
}

static void	ft_execute(t_data *d, char *str, char **save)
{
	int				fd_pipe[2];
	int				id;
	pid_t			pid;

	d->fork = 1;
	pipe(fd_pipe);
	pid = fork();
	if (!pid)
		ft_child(d, str, fd_pipe);
	waitpid(pid, &id, 0);
	close(fd_pipe[1]);
	ft_realloc_bquote(fd_pipe[0], save);
	close(fd_pipe[0]);
	d->fork = 0;
}

char		*ft_bquote(t_data *d, char *str)
{
	char		*tmp;
	char		*ptr;
	char		*save;

	save = ft_strdup(str);
	while ((ptr = ft_strchr(save, '`')))
	{
		tmp = ft_strchr(++ptr, '`');
		if (!tmp)
			return (save);
		tmp = ft_strsub(ptr, 0, tmp - ptr);
		ft_execute(d, tmp, &save);
		ft_strdel(&tmp);
	}
	return (save);
}
