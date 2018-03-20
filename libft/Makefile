# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 10:21:28 by vkovsh            #+#    #+#              #
#    Updated: 2018/01/03 11:58:53 by vkovsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

FLAGS	=	-Wall -Werror -Wextra

CC		=	gcc $(FLAGS)

INC		=	./includes

SRC		= 	ft_islow.c 		\
			ft_memalloc.c 	\
			ft_putendl.c 	\
			ft_strcpy.c 	\
			ft_strmapi.c 	\
			ft_strsub.c		\
			ft_isprint.c	\
			ft_memccpy.c	\
	   		ft_putendl_fd.c	\
			ft_strdel.c		\
			ft_strncat.c	\
	   		ft_strtolower.c	\
			ft_arealpha.c	\
			ft_isupper.c	\
	   		ft_memchr.c		\
			ft_putnbr.c		\
			ft_strdup.c		\
	   		ft_strncmp.c	\
			ft_strtoupper.c	\
			ft_aredigits.c	\
			ft_itoa.c		\
			ft_memcmp.c		\
			ft_putnbr_fd.c	\
			ft_strequ.c		\
			ft_strncpy.c	\
			ft_strtrim.c	\
			ft_atoi.c		\
			ft_lstadd.c		\
			ft_memcpy.c		\
			ft_putstr.c		\
			ft_striter.c	\
			ft_strnequ.c	\
			ft_tolower.c	\
			ft_bzero.c		\
			ft_lstdel.c		\
			ft_memdel.c		\
			ft_putstr_fd.c	\
			ft_striteri.c	\
			ft_strnew.c		\
			ft_toupper.c	\
			ft_isalnum.c	\
			ft_lstdelone.c	\
			ft_memmove.c	\
			ft_strcat.c		\
			ft_strjoin.c	\
			ft_strnstr.c	\
			ft_isalpha.c	\
			ft_lstiter.c	\
			ft_memset.c		\
			ft_strchr.c		\
			ft_strlcat.c	\
			ft_strrchr.c	\
			ft_isascii.c	\
			ft_lstmap.c		\
			ft_putchar.c	\
			ft_strclr.c		\
			ft_strlen.c		\
			ft_strsplit.c	\
			ft_isdigit.c	\
			ft_lstnew.c		\
			ft_putchar_fd.c	\
			ft_strcmp.c		\
			ft_strmap.c		\
			ft_strstr.c		\
			ft_lstcount.c	\
			get_next_line.c	\
			ft_ishex.c		\
			ft_arehex.c

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling" [ $(NAME) ]

%.o: %.c $(INC)/libft.h
	@$(CC) -c -o $@ $< -I $(INC)

clean:
	@rm -f $(OBJ)
	@echo "Cleaning" [ $(NAME) ]

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
