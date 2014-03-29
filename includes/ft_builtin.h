/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 16:45:51 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 17:45:51 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

# include "ft_struct.h"

int			ft_alias(t_data *d, char **arg);
int			ft_cd(t_data *d, char **arg);
int			ft_echo(t_data *d, char **arg);
int			ft_env(t_data *d, char **arg);
int			ft_exit(t_data *d, char **arg);
int			ft_setenv(t_data *d, char **arg);
int			ft_source(t_data *d, char **arg);
int			ft_unalias(t_data *d, char **arg);
int			ft_unsetenv(t_data *d, char **arg);

void		ft_search_alias(t_data *d, char ***tab);
void		ft_putstr_echo(char *str, int *ok);
void		ft_builtin(t_data *d, char **arg, int *i);
void		ft_add_env(t_env **my_env, char *str);
t_env		*ft_new_env(t_env *my_env, char **argv);
void		ft_modify_env(t_env **my_env, char *arg, char *env);
char		*ft_getenv_list(t_env *my_env, char *str);
void		ft_modify_pwd(t_data *d, char *path, int opt);
char		*ft_return_path(t_data *d, char *pwd, char *tmp, char *str);
void		ft_free_alias(t_alias **tmp);

/*
**		ft_create_env.c
*/

void		ft_create_env(t_env **my_env);
char		*ft_create_path(void);
void		ft_levelup_shell(t_data *d);

#endif
