# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 11:21:56 by mmartin           #+#    #+#              #
#    Updated: 2015/02/01 18:47:46 by mmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		Makefile.source

DOBJ		=	obj/

NAME		=	libft.a

OBJ_LIB		=	$(patsubst %.c, $(DOBJ)%.o, $(SRC_LIB))

DEPS		=	$(patsubst %.c, $(DOBJ)%.d, $(SRC_LIB))

DEPENDS		=	-MT $@ -MD -MP -MF $(subst .o,.d,$@)

all:		$(NAME)

$(NAME):	$(OBJ_LIB)
	@echo "\033[32mar \033[33m-rc \033[36m$(NAME) $(OBJ_LIB)\033[0m"
	@ar -rc $(NAME) $(OBJ_LIB)
	@echo "\033[32mranlib \033[36m$(NAME)\033[0m"
	@ranlib $(NAME)
	@echo "\033[33mCompilation of libft.a : \033[32mSuccess\033[0m"

-include	$(OBJ:.o=.d)

$(DOBJ)%.o:	%.c
	@mkdir -p $(DOBJ)
	@mkdir -p $(DOBJ)array
	@mkdir -p $(DOBJ)convert
	@mkdir -p $(DOBJ)divers
	@mkdir -p $(DOBJ)general
	@mkdir -p $(DOBJ)list
	@mkdir -p $(DOBJ)math
	@mkdir -p $(DOBJ)printf
	@mkdir -p $(DOBJ)regex
	@mkdir -p $(DOBJ)share
	@mkdir -p $(DOBJ)string
	@mkdir -p $(DOBJ)test
	@mkdir -p $(DOBJ)write
	@echo "\033[32m$(CC) \033[33m$(CFLAGS) \033[35m$(DEPENDS) \033[36m-c $< -o $@ $(INC)\033[0m"
	@$(CC) $(CFLAGS) $(DEPENDS) -c $< -o $@ $(INC)

clean:
	@echo "\033[31mObjects of libft.a : deleted\033[0m"
	@/bin/rm -f $(OBJ_LIB)

fclean:		clean
	@echo "\033[31mlibft.a : deleted\033[0m"
	@/bin/rm -f $(NAME)

re:			fclean all

.PHONY:		all re fclean clean
