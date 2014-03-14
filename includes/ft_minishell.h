/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 15:00:31 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/12 19:47:19 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <termios.h>
# include "ft_history.h"

typedef struct		s_env
{
	struct s_env	*next;
	char			*tab;
}					t_env;

typedef struct		s_id
{
	int				id;
	int				built;
	pid_t			father;
}					t_id;

typedef struct		s_tty
{
	struct termios	backup;
	struct termios	new_term;
	int				fd;
	int				flag;
}					t_tty;

typedef struct		s_line
{
	struct s_line	*next;
	struct s_line	*prev;
	char			c;
	int				pos;
}					t_line;

typedef struct		s_tmp
{
	t_line			*line;
	t_line			*first;
	t_line			*last;
	struct s_tmp	*next;
	struct s_tmp	*prev;
}					t_tmp;

typedef struct		s_data
{
	t_env			*my_env;
	t_history		*history;
	t_history		*first_hist;
	t_history		*last_hist;
	t_tmp			*tmp_hist;
	t_tty			tty;
	t_line			*line;
	t_line			*first;
	t_line			*last;
	t_line			*cpy;
	int				fork;
	char			*str;
	int				len_prompt;
	int				pipe;
	int				save_fd[3];
	char			buff[8];
}					t_data;

/*
**		History
*/

void		ft_history(t_data *d);
void		ft_add_tmp(t_data *d);
void		ft_reset_history(t_data *d);

/*
**		Misc
*/

void		ft_check_option(int argc, char **argv, t_data *d);
char		*ft_get_word(char *str);
void		ft_print_octale(char *str, int *i);
void		ft_print_hexa(char *str, int *i);
int			ft_prompt(t_data *d);
void		ft_signal(void);
char		**ft_strsplit_shell(char *str);
char		*ft_tilde(char *str, t_data *d);

#endif
