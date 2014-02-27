/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 17:00:22 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/27 11:53:51 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HISTORY_H
# define FT_HISTORY_H

typedef struct		s_hist
{
	struct s_hist	*next;
	struct s_hist	*prev;
	char			*line;
	int				flag;
}					t_history;

void		ft_create_history(char *ptr, t_history **history);
void		ft_add_history(t_history **history, char *line);
t_history	*ft_first_history(t_history *hist);
t_history	*ft_last_history(t_history *hist);

#endif
