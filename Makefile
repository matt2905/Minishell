# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/03 13:39:05 by mmartin           #+#    #+#              #
#    Updated: 2015/01/30 20:24:26 by mmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		libft/Makefile.source

include		Makefile.source

export	CFLAGS	=	-Wall -Wextra -Werror -g

export	CC		=	gcc

export	INC		=	-I $(PWD)/libft/includes -I $(PWD)/printf/includes

DOBJ		=	obj/

NAME		=	ft_sh1

INC			+=	-I includes

OBJ			=	$(patsubst %.c, $(DOBJ)%.o, $(SRC))

DEPS		=	$(patsubst %.c, $(DOBJ)%.d, $(SRC))

LIB			=	-L libft -lft -ltermcap

DEPENDS		=	-MT $@ -MD -MP -MF $(subst .o,.d,$@)

OBJ_LIB		=	$(libft/SRC_LIB:.c=.o)

HEAD_LIB	=	libft/includes/libft.h libft/includes/ft_struct_lib.h

all:			./libft/libft.a $(NAME)

libft/libft.a:	libft/$(OBJ_LIB) $(HEAD_LIB)
	@Make -C libft

$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo ""
	@echo "\033[33m"Compilation of $(NAME) : "\033[32m"Success"\033[0m"

-include		$(OBJ:.o=.d)

$(DOBJ)%.o:		%.c
	@mkdir -p $(DOBJ)
	@mkdir -p $(DOBJ)builtin
	@mkdir -p $(DOBJ)exec
	@mkdir -p $(DOBJ)history
	@mkdir -p $(DOBJ)lex_pars
	@mkdir -p $(DOBJ)misc
	@mkdir -p $(DOBJ)termcap
	@echo -n .
	@$(CC) $(CFLAGS) $(DEPENDS) -c $< -o $@ $(INC)

clean:
	@/bin/rm -rf $(DOBJ)
	@echo "\033[31m"Objects of $(NAME) : deleted"\033[0m"

fclean:			clean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf $(NAME).dSYM
	@echo "\033[31m"$(NAME) : deleted"\033[0m"
	@Make fclean -C libft

re:				fclean all

.PHONY:			all clean fclean re
