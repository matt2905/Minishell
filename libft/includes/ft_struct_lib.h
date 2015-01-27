/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 21:34:09 by mmartin           #+#    #+#             */
/*   Updated: 2015/01/27 12:46:16 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_LIB_H
# define FT_STRUCT_LIB_H

# include <string.h>

/*
**		LIST_GENERAL
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**		TRE_GENERAL
*/

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	char			*item;
}					t_btree;

/*
**		ATOF
*/

typedef struct		s_atof
{
	double			ip;
	double			fp;
	int				div;
	int				sign;
	int				flag;
}					t_atof;

/*
**		GET_NEXT_LINE
*/

typedef struct		s_info
{
	char			*start;
	char			*buf;
	int				fd;
	int				offset;
	struct s_info	*next;
}					t_info;

/*
**		PRINTF
*/

typedef struct		s_printf
{
	char			*sign;
	char			*sharp;
	int				width;
	int				pad;
	int				precision;
	char			*dot;
	char			*length;
}					t_printf;

#endif
