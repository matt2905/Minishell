/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 17:00:22 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 20:25:16 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HISTORY_H
# define FT_HISTORY_H

# include "ft_struct.h"

void		ft_history(t_data *d);
void		ft_add_tmp(t_data *d);
void		ft_reset_history(t_data *d);
void		ft_create_history(char *ptr, t_history **history);
void		ft_add_history(t_history **history, char *line);
t_history	*ft_first_history(t_history *hist);
t_history	*ft_last_history(t_history *hist);
void		ft_free_history(t_history **his);

#endif
