/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 17:13:15 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/25 18:50:29 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct		s_env
{
	struct s_env	*next;
	char			*tab;
}					t_env;

typedef struct		s_builtin
{
	char			*cmd;
	void			(* func)(t_env **, char **);
}					t_builtin;

typedef struct		s_lex
{
	char			*token;
	struct s_lex	*next;
}					t_lex;

typedef struct		s_param
{
	struct s_param	*next;
	char			*str;
}					t_param;

typedef struct		s_pars
{
	struct s_pars	*left;
	struct s_pars	*right;
	char			*token;
	t_param			*param;
}					t_pars;

/*
**		Builtin
*/

void	ft_create_env(t_env **my_env);
void	ft_add_env(t_env **my_env, char *str);
void	ft_modify_env(t_env **my_env, char *str, char *env);
void	ft_cd(t_env **my_env, char **argv);
void	ft_env(t_env **my_env, char **argv);
void	ft_exit(t_env **my_env, char **argv);
void	ft_setenv(t_env **my_env, char **argv);
void	ft_unsetenv(t_env **my_env, char **argv);
void	ft_builtin(t_env **my_env, char **argv, int *i);
char	*ft_create_path(void);
char	*ft_getenv_list(t_env **my_env, char *var);

/*
**		Exec
*/

char	**ft_convert_tab(t_env **my_env);
int		ft_exec(char **my_env, char **argv);
char	*ft_search_path(char **my_env, char *argv);
char	*ft_getenv(char **my_env, char *var);

/*
**		Lexer
*/

void	ft_lexer(char *line, t_lex **lex);
void	ft_add_token(t_lex **lex, char *line, int end);
void	ft_destroy_lex(t_lex **lex);

/*
**		Parser
*/

void	ft_parser(t_lex *lex, t_pars **pars);
void	ft_add_node(t_pars **pars, char *str);

/*
**		Misc
*/

char	**ft_tilde(char **argv, t_env **my_env);
int		ft_prompt(t_env **my_env);

#endif
