/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexpars.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:16:48 by amorfan           #+#    #+#             */
/*   Updated: 2014/03/07 13:09:15 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXPARS_H
# define FT_LEXPARS_H

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

void	ft_add_lexer(t_lexer **root, char *str, int type, int rank);
void	ft_add_tree(t_parser **tree, t_lexer *tmp, t_lexer *list, int check);
void	ft_free_lex(t_lexer **lex);
void	ft_free_pars(t_parser **pars);
char	*ft_search_word(char **str, int i, char c);

/*
**		ft_lexer.c
*/

int		ft_check_tok(char c);
void	ft_lexer(t_lexer **root, char *str);

/*
**		ft_parser.c
*/

void	ft_parser(t_parser **tree, t_lexer *list, int check);

#endif
