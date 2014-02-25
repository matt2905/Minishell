/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 15:00:31 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/25 17:03:52 by mmartin          ###   ########.fr       */
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

typedef struct		s_data
{
	t_env			*my_env;
	t_history		*history;
	t_history		*first_hist;
	t_history		*last_hist;
	t_tty			tty;
	t_line			*line;
	t_line			*first;
	t_line			*last;
	char			*str;
	int				len_prompt;
	int				y;
	int				save_fd[2];
	char			buff[6];
}					t_data;

/*
**		History
*/

void		ft_history(t_data *d);

/*
**		Exec
*/

int			ft_exec(char **my_env, char **arg);
char		*ft_search_path(char **my_env, char *argv, int *flag);
char		*ft_getenv(char **my_env, char *var);
char		**ft_convert_ltt(t_env *my_env);

/*
**		Lexer
*/

/*
**		Parser
*/

/*
**		Misc
*/

int			ft_prompt(t_data *d);
char		**ft_tilde(char **tab, t_data *d);
void		ft_check_option(int argc, char **argv, t_data *d);

#endif
