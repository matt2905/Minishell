/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 20:00:20 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/26 17:50:11 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

# include <termios.h>

typedef struct			s_alias
{
	char				*keyword;
	char				*value;
	struct s_alias		*next;
}						t_alias;

/*
**		Env
*/

typedef struct			s_env
{
	struct s_env		*next;
	char				*tab;
}						t_env;

/*
**		Fork
*/

typedef struct			s_id
{
	int					id;
	int					built;
	pid_t				child;
	pid_t				father;
}						t_id;

/*
**		Terminal
*/

typedef struct			s_tty
{
	struct termios		backup;
	struct termios		new_term;
	int					fd;
	int					flag;
}						t_tty;

/*
**		Command's line
*/

typedef struct			s_line
{
	struct s_line		*next;
	struct s_line		*prev;
	char				c;
	int					pos;
}						t_line;

typedef struct			s_tmp
{
	t_line				*line;
	t_line				*first;
	t_line				*last;
	struct s_tmp		*next;
	struct s_tmp		*prev;
}						t_tmp;

/*
**		History
*/

typedef struct			s_hist
{
	struct s_hist		*next;
	struct s_hist		*prev;
	char				*line;
	int					flag;
	char				miss;
}						t_history;

/*
**		All
*/

typedef struct			s_data
{
	t_tty				tty;
	t_env				*my_env;
	t_history			*history;
	t_history			*first_hist;
	t_history			*last_hist;
	t_tmp				*tmp_hist;
	t_line				*line;
	t_line				*first;
	t_line				*last;
	t_line				*cpy;
	t_alias				*alias;
	char				*str;
	char				buff[8];
	int					len_prompt;
	int					pipe;
	int					fork;
	int					save_fd[3];
	char				*save_pwd;
	char				*save_old;
}						t_data;

/*
**		Builtin
*/

typedef struct			s_echo
{
	char				c;
	int					back;
	char				val;
	int					newback;
}						t_echo;

/*
**		Lexer / Parser
*/

typedef struct			s_lexer
{
	char				*str;
	int					type;
	int					rank;
	int					flag;
	struct s_lexer		*prev;
	struct s_lexer		*next;
}						t_lexer;

typedef struct			s_parser
{
	char				*str;
	int					type;
	int					rank;
	struct s_parser		*left;
	struct s_parser		*right;
}						t_parser;

typedef struct			s_token
{
	char				c;
	int					type;
	int					rank;
}						t_token;

/*
**		tableau de pointeur de fonction.
*/

typedef struct			s_exec
{
	int					type;
	void				(*func)(t_parser *, t_data *);
}						t_exec;

typedef struct			s_builtin
{
	char				*cmd;
	int					(*func)(t_data *, char **);
}						t_builtin;

typedef struct			s_tab
{
	char				*buffer;
	int					(*func)(t_data *);
}						t_tab;

#endif
