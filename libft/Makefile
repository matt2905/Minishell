# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 11:21:56 by mmartin           #+#    #+#              #
#    Updated: 2014/01/24 16:13:46 by mmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_atoi.c				\
			ft_itoa.c				\
			ft_uitoa.c				\
			ft_bzero.c				\
			ft_memset.c				\
			ft_memcpy.c				\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_strlen.c				\
			ft_tablen.c				\
			ft_strdup.c				\
			ft_strcpy.c				\
			ft_strcat.c				\
			ft_strchr.c				\
			ft_strstr.c				\
			ft_strcmp.c				\
			ft_memdel.c				\
			ft_strnew.c				\
			ft_strdel.c				\
			ft_strclr.c				\
			ft_strmap.c				\
			ft_strequ.c				\
			ft_strsub.c				\
			ft_putstr.c				\
			ft_putnbr.c				\
			ft_lstnew.c				\
			ft_strndup.c			\
			ft_putchar.c			\
			ft_putendl.c			\
			ft_strjoin.c			\
			ft_strtrim.c			\
			ft_strnequ.c			\
			ft_strmapi.c			\
			ft_strncpy.c			\
			ft_memccpy.c			\
			ft_memmove.c			\
			ft_strncat.c			\
			ft_strlcat.c			\
			ft_strrchr.c			\
			ft_strnstr.c			\
			ft_strncmp.c			\
			ft_isalpha.c			\
			ft_isdigit.c			\
			ft_isalnum.c			\
			ft_isascii.c			\
			ft_isprint.c			\
			ft_toupper.c			\
			ft_tolower.c			\
			ft_striter.c			\
			ft_memalloc.c			\
			ft_striteri.c			\
			ft_strsplit.c			\
			ft_putnbr_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putchar_fd.c			\
			get_next_line.c			\
			ft_strnsplit_space.c	\

OBJ		=	$(SRC:.c=.o)

all:		$(LIBFT)

$(LIBFT):	$(OBJ)
	@ar -rc $(LIBFT) $(OBJ)
	@ranlib $(LIBFT)
	@echo ""
	@echo "\033[33m"Compilation of libft.a : "\033[32m"Succes"\033[0m"

%.o:		%.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@echo "\033[31m"Objects of libft.a : deleted"\033[0m"
	@/bin/rm -f $(OBJ)

fclean:		clean
	@echo "\033[31m"Deletion of libft.a"\033[0m"
	@/bin/rm -f $(LIBFT)

re:			fclean all

.PHONY:		all re fclean clean
