/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 15:00:31 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 13:41:12 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include "ft_struct.h"

/*
**		Misc
*/

void		ft_check_option(int argc, char **argv, t_data *d);
char		*ft_get_word(char *str);
void		ft_print_octale(char *str, int *i);
void		ft_print_hexa(char *str, int *i);
int			ft_prompt(t_data *d);
void		ft_signal(void);
void		ft_init_source(t_data *d);
char		**ft_strsplit_shell(char *str);
char		*ft_tilde(char *str, t_data *d);

#endif
