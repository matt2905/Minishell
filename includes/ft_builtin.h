/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 16:45:51 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/03 12:39:54 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BULTIN_H
# define FT_BULTIN_H

# include "ft_minishell.h"

typedef struct		s_builtin
{
	char			*cmd;
	int				(* func)(t_data *, char **);
}					t_builtin;

int		ft_cd(t_data *d, char **arg);
int		ft_echo(t_data *d, char **arg);
int		ft_env(t_data *d, char **arg);
int		ft_exit(t_data *d, char **arg);
int		ft_setenv(t_data *d, char **arg);
int		ft_unsetenv(t_data *d, char **arg);

void	ft_builtin(t_data *d, char **arg, int *i);
void	ft_create_env(t_env **my_env);
void	ft_add_env(t_env **my_env, char *str);
void	ft_modify_env(t_env **my_env, char *arg, char *env);
char	*ft_create_path(void);
char	*ft_getenv_list(t_env *my_env, char *str);

#endif
