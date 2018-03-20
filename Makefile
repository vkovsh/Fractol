# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 12:03:00 by vkovsh            #+#    #+#              #
#    Updated: 2018/01/28 15:23:52 by vkovsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./srcs/
INC_PATH = ./includes/ $(LIB_PATH)/includes/
OBJ_PATH = ./obj/
LIB_PATH = ./libft/
LIB_LNK	= -lmlx -framework OpenGL -framework AppKit -L ./libft -lft -lpthread

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_NAME = fractol.c		\
		   mandelbrot.c		\
		   events.c			\
		   checker.c		\
		   event_helper.c	\
		   graph.c			\
		   checker2.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) -o $(NAME) $(OBJ) $(LIB_LNK)
	@echo "Compiling" [ $(NAME) ]

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@echo "Linking" [ $< ]

clean:
	@make -C $(LIB_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj Fractol..."

fclean: clean
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)
	@echo "Remove..." [ $(NAME) ]

re: fclean all
