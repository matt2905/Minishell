/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexpars.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:16:48 by amorfan           #+#    #+#             */
/*   Updated: 2014/03/25 20:25:15 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXPARS_H
# define FT_LEXPARS_H

# include "ft_struct.h"

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
