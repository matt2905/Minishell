/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 16:56:18 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 11:32:46 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMCAP_H
# define FT_TERMCAP_H

# include "ft_struct.h"

int			ft_alt_down(t_data *d);
int			ft_alt_left(t_data *d);
int			ft_alt_right(t_data *d);
int			ft_alt_up(t_data *d);
int			ft_backspace(t_data *d);
int			ft_ctrlc(t_data *d);
int			ft_ctrll(t_data *d);
int			ft_cut(t_data *d);
int			ft_delete(t_data *d);
int			ft_end(t_data *d);
int			ft_exit_term(t_data *d);
int			ft_go_down(t_data *d);
int			ft_go_left(t_data *d);
int			ft_go_right(t_data *d);
int			ft_go_up(t_data *d);
int			ft_home(t_data *d);
int			ft_paste(t_data *d);
int			ft_print(t_data *d);
int			ft_return(t_data *d);
int			ft_tab(t_data *d);

int			ft_check_pos(t_line *line, int len_prompt);
void		ft_init_term(t_data *d);
int			ft_int_putchar(int c);
void		ft_oneshot(t_data *d);
void		ft_backup_termcap(t_data *d);
void		ft_reset_termcap(t_data *d);
void		ft_termcap(t_data *d);

/*
**		ft_struct.c
*/

t_line		*ft_find_first(t_line *line);
t_line		*ft_find_last(t_line *line);
void		ft_add_char(t_line **tmp, char c);
t_line		*ft_new_char(char c);

/*
**		ft_tool_list.c
*/

void		ft_free_list(t_line *list);
void		ft_print_list(t_data *d);

#endif
