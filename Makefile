# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/03 13:39:05 by mmartin           #+#    #+#              #
#    Updated: 2015/01/27 11:57:29 by mmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		libft/Makefile.source

include		Makefile.source

export	CFLAGS	=	-Wall -Wextra -Werror -g

export	CC		=	gcc

export	INC		=	-I $(PWD)/libft/includes -I $(PWD)/printf/includes

NAME		=	42sh

INC			+=	-I includes

HEAD		=	includes/ft_builtin.h	\
				includes/ft_exec.h		\
				includes/ft_history.h	\
				includes/ft_lexpars.h	\
				includes/ft_minishell.h	\
				includes/ft_termcap.h	\
				includes/ft_struct.h

OBJ			=	$(SRC:.c=.o)

LIB			=	-L libft -lft -ltermcap

OBJ_LIB		=	$(libft/SRC_LIB:.c=.o)

HEAD_LIB	=	libft/includes/libft.h libft/includes/ft_struct_lib.h

all:			libft.a $(NAME)

libft.a:		libft/$(OBJ_LIB) $(HEAD_LIB)
	@Make -C libft

$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo ""
	@echo "\033[33m"Compilation of $(NAME) : "\033[32m"Success"\033[0m"

$(OBJ):			$(HEAD) libft.a

%.o:			%.c $(HEAD)
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[31m"Objects of $(NAME) : deleted"\033[0m"

fclean:			clean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf $(NAME).dSYM
	@echo "\033[31m"$(NAME) : deleted"\033[0m"
	@Make fclean -C libft

re:				fclean all

.PHONY:			all clean fclean re
