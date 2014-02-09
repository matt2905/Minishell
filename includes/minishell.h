/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 15:00:31 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/07 18:03:01 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <termios.h>

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
**		Builtin
*/

typedef struct		s_builtin
{
	char			*cmd;
	void			(* func)(t_data *, char **);
}					t_builtin;

void	ft_cd(t_data *d, char **arg);
void	ft_env(t_data *d, char **arg);
void	ft_exit(t_data *d, char **arg);
void	ft_setenv(t_data *d, char **arg);
void	ft_unsetenv(t_data *d, char **arg);

void	ft_builtin(t_data *d, char **arg, int *i);
void	ft_create_env(t_env **my_env);
void	ft_add_env(t_env **my_env, char *str);
void	ft_modify_env(t_env **my_env, char *arg, char *env);
char	*ft_create_path(void);
char	*ft_getenv_list(t_env *my_env, char *str);

/*
**		Termcap
*/

typedef struct		s_tab
{
	char			*buffer;
	int				(* func)(t_data *);
}					t_tab;

int		ft_backspace(t_data *d);
int		ft_ctrlc(t_data *d);
int		ft_delete(t_data *d);
int		ft_end(t_data *d);
int		ft_exit_term(t_data *d);
int		ft_go_down(t_data *d);
int		ft_go_left(t_data *d);
int		ft_go_right(t_data *d);
int		ft_go_up(t_data *d);
int		ft_home(t_data *d);
int		ft_print(t_data *d);
int		ft_return(t_data *d);
int		ft_tab(t_data *d);

void	ft_init_term(t_data *d);
void	ft_termcap(t_data *d);
t_line	*ft_find_first(t_line *line);
t_line	*ft_find_last(t_line *line);
void	ft_add_char(t_line **tmp, char c);
t_line	*ft_new_char(char c);
int		ft_int_putchar(int c);
void	ft_free_list(t_line *list);
void	ft_print_list(t_data *d);

/*
**		Exec
*/

int		ft_exec(char **my_env, char **arg);
char	*ft_search_path(char **my_env, char *argv, int *flag);
char	*ft_getenv(char **my_env, char *var);
char	**ft_convert_ltt(t_env *my_env);

/*
**		Lexer
*/

/*
**		Parser
*/

/*
**		Misc
*/

int		ft_prompt(t_data *d);
char	**ft_tilde(char **tab, t_data *d);
void	ft_check_option(int argc, char **argv, t_data *d);

#endif
