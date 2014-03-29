# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 11:21:56 by mmartin           #+#    #+#              #
#    Updated: 2014/03/25 21:38:47 by mmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		Makefile.source

NAME		=	../libft.a

OBJ_LIB		=	$(SRC_LIB:.c=.o)

HEAD		=	includes/libft.h includes/ft_struct_lib.h

all:		$(NAME)

$(NAME):	$(OBJ_LIB)
	@ar -rc $(NAME) $(OBJ_LIB)
	@ranlib $(NAME)
	@echo ""
	@echo "\033[33m"Compilation of libft.a : "\033[32m"Succes"\033[0m"

$(OBJ_LIB):		$(HEAD)

%.o:		%.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@echo "\033[31m"Objects of libft.a : deleted"\033[0m"
	@/bin/rm -f $(OBJ_LIB)

fclean:		clean
	@echo "\033[31m"libft.a : deleted"\033[0m"
	@/bin/rm -f $(NAME)

re:			fclean all

.PHONY:		all re fclean clean
