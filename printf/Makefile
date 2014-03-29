# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 09:33:34 by mmartin           #+#    #+#              #
#    Updated: 2014/03/25 21:42:55 by mmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		Makefile.source

NAME		=	../libprintf.a

OBJ_PRINTF	=	$(SRC_PRINTF:.c=.o)

HEAD		=	includes/printf.h includes/ft_struct_printf.h

all:				$(NAME)

$(NAME):			$(OBJ_PRINTF)
	@ar -rc $(NAME) $(OBJ_PRINTF)
	@ranlib $(NAME)
	@echo ""
	@echo "\033[33m"Compilation of libprintf.a : "\033[32m"Success"\033[0m"

$(OBJ_PRINTF):		$(HEAD)

%.o:				%.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@echo "\033[31m"Objects of libprintf.a : deleted"\033[0m"
	@/bin/rm -f $(OBJ_PRINTF)

fclean:				clean
	@echo "\033[31m"libprintf.a : deleted"\033[0m"
	@/bin/rm -f $(NAME)

re:					fclean all

.PHONY:				all re clean fclean
