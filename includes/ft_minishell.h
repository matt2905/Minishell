/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 15:00:31 by mmartin           #+#    #+#             */
/*   Updated: 2015/03/30 13:18:28 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include "ft_struct.h"

/*
**		Misc
*/

void		ft_check_option(int argc, char **argv, t_data *d);
t_data		*ft_get_data(t_data *d);
char		*ft_get_word(char *str);
void		ft_init_source(t_data *d);
int			ft_print_process(t_data *d, t_id *proc);
void		ft_print_tab(char **result);
int			ft_prompt(int reset_line);
void		ft_puterror(char const *s);
char		*ft_replace_var(t_data *d, char *str);
void		ft_signal(void);
char		**ft_strsplit_shell(char *str);
char		*ft_tilde(char *str, t_data *d);

/*
**	ft_print.c
*/

void		ft_print_hexa(char *str, int *i);
void		ft_print_octale(char *str, int *i);

#endif
