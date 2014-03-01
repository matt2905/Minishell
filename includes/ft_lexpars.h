/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:16:48 by amorfan           #+#    #+#             */
/*   Updated: 2014/03/01 10:48:25 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXPARS_H
#define FT_LEXPARS_H

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

typedef struct			s_var
{
	int					check;
	char				sens;
}						t_var;

void	ft_lexer(t_lexer **root, char *str);
void	ft_add_lexer(t_lexer **root, char *str, int type, int rank);
void	ft_free_lex(t_lexer **lex);
void	ft_parser(t_parser **tree, t_lexer *list);
void	ft_priority(t_parser **tree, t_lexer *list, t_var v);
void	ft_add_tree(t_parser **tree, t_lexer *tmp, t_lexer *list, t_var v);
void	ft_free_pars(t_parser **pars);

#endif
