/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:48:33 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/01 11:03:16 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_H
# define FT_EXEC_H

# include "ft_minishell.h"
# include "ft_lexpars.h"

typedef struct		s_exec
{
	int				type;
	void			(*func)(t_parser *, t_data *);
}					t_exec;

void		ft_amp(t_parser *parser, t_data *d);
void		ft_or(t_parser *parser, t_data *d);
void		ft_pipe(t_parser *parser, t_data *d);
void		ft_less(t_parser *parser, t_data *d);
void		ft_dless(t_parser *parser, t_data *d);
void		ft_great(t_parser *parser, t_data *d);
void		ft_dgreat(t_parser *parser, t_data *d);
void		ft_and(t_parser *parser, t_data *d);
void		ft_sep(t_parser *parser, t_data *d);

int			ft_exec(char **my_env, char **arg);
char		*ft_search_path(char **my_env, char *argv, int *flag);
char		*ft_getenv(char **my_env, char *var);
char		**ft_convert_ltt(t_env *my_env);
void		ft_process_tree(t_parser *parser, t_data *d);

/*
**		ft_processing.c
*/

void		ft_processing(t_data *d);
void		ft_process(t_data *d, char *str);

#endif
