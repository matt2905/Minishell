/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 17:13:15 by mmartin           #+#    #+#             */
/*   Updated: 2014/01/24 15:06:53 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct		s_builtin
{
	char			*cmd;
	char			**(* func)(char **, char **);
}					t_builtin;

typedef struct		s_lex
{
	char			*token;
	struct s_lex	*next;
}					t_lex;

/*
**		Builtin
*/

char	**ft_create_env(char **my_env);
char	**ft_cd(char **my_env, char **argv);
char	**ft_env(char **my_env, char **argv);
char	**ft_exit(char **my_env, char **argv);
char	**ft_setenv(char **my_env, char **argv);
char	**ft_unsetenv(char **my_env, char **argv);
char	**ft_builtin(char **my_env, char **argv, int *i);
char	*ft_create_path(void);
int		ft_getenv_pos(char **my_env, char *var);

/*
**		Exec
*/

int		ft_exec(char **my_env, char **argv);
char	*ft_search_path(char **my_env, char *argv);
char	*ft_getenv(char **my_env, char *var);

/*
**		Lexer
*/

void	ft_lexer(char *line, t_lex **lex);
void	ft_add_token(t_lex **lex, char *line, int start, int end);
void	ft_destroy_lex(t_lex **lex);

/*
**		Misc
*/

char	**ft_tilde(char **argv, char **my_env);
int		ft_prompt(char **my_env);

#endif
