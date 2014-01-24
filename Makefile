# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 09:33:34 by mmartin           #+#    #+#              #
#    Updated: 2014/01/24 15:56:00 by mmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_minishell2

export	LIBFT	=	$(PWD)/libft.a

export	PRINTF	=	$(PWD)/libprintf.a

export	CC		=	gcc

export	CFLAGS	=	-Wall -Wextra -Werror -pedantic -g

export	INC		=	-I $(PWD)/libft/includes -I $(PWD)/printf/includes

INC		+=	-I includes

LIB		=	-L./ -lft -lprintf

SRC		=	main.c					\
			builtin/ft_cd.c			\
			builtin/ft_env.c		\
			builtin/ft_exit.c		\
			builtin/ft_setenv.c		\
			builtin/ft_builtin.c	\
			builtin/ft_unsetenv.c	\
			builtin/ft_create_env.c	\
			builtin/ft_getenv_pos.c	\
			exec/ft_exec.c			\
			exec/ft_getenv.c		\
			exec/ft_search_path.c	\
			lexer/ft_lexer.c		\
			lexer/ft_add_token.c	\
			lexer/ft_destroy_lex.c	\
			misc/ft_tilde.c			\
			misc/ft_prompt.c		\

OBJ		=	$(SRC:.c=.o)

all:		$(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	@Make -C libft

$(PRINTF):
	@Make -C printf

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo ""
	@echo "\033[33m"Compilation of ft_minishell : "\033[32m"Success"\033[0m"

%.o:		%.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@echo "\033[31m"Objects of ft_minishell : deleted"\033[0m"
	@/bin/rm -f $(OBJ)

fclean:		clean
	@echo "\033[31m"ft_minishell : deleted"\033[0m"
	@/bin/rm -f $(NAME)

fcleanlib:
	@Make fclean -C libft
	@Make fclean -C printf

re:			fclean fcleanlib all

.PHONY:		all clean fclean fcleanlib re
