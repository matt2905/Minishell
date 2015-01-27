/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 09:43:29 by mmartin           #+#    #+#             */
/*   Updated: 2015/01/27 11:59:09 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "ft_struct_lib.h"

int		ft_printf(const char *str, ...);
int		ft_get_flags(const char *str, t_printf *flags, va_list ap);
void	ft_printchar(char c, int *i);
void	ft_printstr(char *str, t_printf *flags, int *i);
void	ft_printnbr(char *str, t_printf *flags, char *c, int *i);

#endif
