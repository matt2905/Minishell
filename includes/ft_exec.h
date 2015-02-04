/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:48:33 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/04 18:22:59 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_H
# define FT_EXEC_H

# include "ft_struct.h"

void		ft_amp(t_parser *parser, t_data *d);
void		ft_or(t_parser *parser, t_data *d);
void		ft_pipe(t_parser *parser, t_data *d);
void		ft_less(t_parser *parser, t_data *d);
void		ft_dless(t_parser *parser, t_data *d);
void		ft_great(t_parser *parser, t_data *d);
void		ft_dgreat(t_parser *parser, t_data *d);
void		ft_and(t_parser *parser, t_data *d);
void		ft_sep(t_parser *parser, t_data *d);

int			ft_exec(char **my_env, char **arg, int ok);
char		*ft_search_path(char **my_env, char *argv, int *flags);
char		*ft_getenv(char **my_env, char *var);
char		**ft_convert_ltt(t_env *my_env);
void		ft_process_tree(t_parser *parser, t_data *d);
char		*ft_bquote(t_data *d, char *str);

/*
**		ft_processing.c
*/

void		ft_processing(t_data *d, char *str);
void		ft_process(t_data *d, char *str);

/*
**		ft_process.c
*/

t_id		*ft_create_process(pid_t pid, int nb, char *cmd);
void		ft_add_process(t_data *d, int nb, char *cmd, pid_t pid);
void		ft_delete_process(t_data *d);
int			ft_check_process(t_data *d);
void		ft_delete_all_process(t_data *d);

#endif
