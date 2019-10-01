# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idris <idris@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 17:46:29 by idris             #+#    #+#              #
#    Updated: 2019/10/01 19:14:33 by idris            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Werror -Wextra

MLX = -framework OpenGL -framework AppKit

CC = gcc

SRC_NAME = main.c mlx_img.c

OBJ_NAME = $(SRC_NAME:.c=.o)

LIB = ./libft/libft.a

LIBMLX = ./minilibx_macos/libmlx.a

all: $(NAME)

$(LIB):
	make -C ./libft

$(LIBMLX):
	make -C ./minilibx_macos

$(NAME): $(LIB) $(LIBMLX) $(OBJ_NAME)
	$(CC) -c $(SRC_NAME)
	$(CC) $(MLX) -o $(NAME) $(OBJ_NAME) libft/libft.a minilibx_macos/libmlx.a

clean:
	rm -f $(OBJ_NAME)
	make clean -C ./libft

fclean:
	rm -f $(OBJ_NAME)
	rm -f $(NAME)
	make fclean -C ./libft
	make clean -C ./minilibx_macos

re: fclean all
