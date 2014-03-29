/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_printf.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 21:41:09 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/25 21:41:43 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_PRINTF_H
# define FT_STRUCT_PRINTF_H

typedef struct	s_printf
{
	char		*sign;
	char		*sharp;
	int			width;
	int			pad;
	int			precision;
	char		*dot;
	char		*length;
}				t_printf;

#endif
