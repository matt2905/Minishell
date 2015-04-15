# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/03 13:39:05 by mmartin           #+#    #+#              #
#    Updated: 2015/04/15 16:18:40 by mmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		libft/Makefile.source

include		Makefile.source

export	CFLAGS	=	-Wall -Wextra -Werror

export	CC		=	gcc

export	INC		=	-I libft/includes

LIBFT		=	libft/libft.a

DOBJ		=	obj/

NAME		=	42sh

INC			+=	-I includes

OBJ			=	$(patsubst %.c, $(DOBJ)%.o, $(SRC))

DEPS		=	$(patsubst %.c, $(DOBJ)%.d, $(SRC))

LIB			=	-L libft -lft -ltermcap

DEPENDS		=	-MT $@ -MD -MP -MF $(subst .o,.d,$@)

all:		$(LIBFT) $(NAME)

$(LIBFT):
	@Make -C libft

$(NAME):		$(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
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
	@$(CC) $(CFLAGS) $(DEPENDS) -c $< -o $@ $(INC)
	@echo "\033[32m$(CC) \033[33m$(CFLAGS) \033[35m$(DEPENDS) \033[36m-c $< -o $@ $(INC)\033[0m"

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
