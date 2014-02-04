# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/03 13:39:05 by mmartin           #+#    #+#              #
#    Updated: 2014/02/04 14:06:26 by mmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		libft/Makefile.source

export	CFLAGS	=	-Wall -Wextra -Werror -g

export	CC		=	gcc

export	INC		=	-I $(PWD)/libft/includes -I $(PWD)/printf/includes

NAME		=	ft_minishell3

INC			+=	-I includes

HEAD		=	includes/minishell.h

SRC			=	main.c						\
				builtin/ft_builtin.c		\
				builtin/ft_env.c			\
				builtin/ft_exit.c			\
				builtin/ft_cd.c				\
				builtin/ft_setenv.c			\
				builtin/ft_unsetenv.c		\
				builtin/ft_add_env.c		\
				builtin/ft_create_env.c		\
				builtin/ft_modify_env.c		\
				builtin/ft_getenv_list.c	\
				exec/ft_exec.c				\
				exec/ft_convert_ltt.c		\
				exec/ft_getenv.c			\
				exec/ft_search_path.c		\
				misc/ft_check_option.c		\
				misc/ft_prompt.c			\
				misc/ft_tilde.c				\
				termcap/ft_init_term.c		\

OBJ			=	$(SRC:.c=.o)

LIB			=	-L./ -lft -lprintf

OBJ_LIB		=	$(libft/SRC_LIB:.c=.o)

HEAD_LIB	=	libft/includes/libft.h libft/includes/get_next_line.h

HEAD_PRINTF	=	printf/includes/printf.h

all:			libft.a libprintf.a $(NAME)

libft.a:		libft/$(OBJ_LIB) $(HEAD_LIB)
	@Make -C libft

libprintf.a:	printf/$(OBJ_PRINTF) $(HEAD_PRINTF)
	@Make -C printf

$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo ""
	@echo "\033[33m"Compilation of $(NAME) : "\033[32m"Success"\033[0m"

$(OBJ):			$(HEAD) libft.a libprintf.a

%.o:			%.c $(HEAD)
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[31m"Objects of $(NAME) : deleted"\033[0m"

fclean:			clean
	@/bin/rm -f $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"

fcleanlib:
	@Make fclean -C libft
	@Make fclean -C printf

re:				fclean fcleanlib all

.PHONY:			all clean fclean fcleanlib re
