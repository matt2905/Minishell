# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 09:33:34 by mmartin           #+#    #+#              #
#    Updated: 2014/01/27 15:59:51 by mmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../libprintf.a

SRC		=	ft_printf.c		\
			ft_redirect.c	\
			ft_printstr.c	\
			ft_printnbr.c	\

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ""
	@echo "\033[33m"Compilation of libprintf.a : "\033[32m"Success"\033[0m"

%.o:		%.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@echo "\033[31m"Objects of libprintf.a : deleted"\033[0m"
	@/bin/rm -f $(OBJ)

fclean:		clean
	@echo "\033[31m"libprintf.a : deleted"\033[0m"
	@/bin/rm -f $(NAME)

re:			fclean all

.PHONY:		all re clean fclean
