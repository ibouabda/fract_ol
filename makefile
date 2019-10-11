# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 17:46:29 by idris             #+#    #+#              #
#    Updated: 2019/10/11 16:35:42 by ibouabda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = fractol

# CFLAGS = -Wall -Werror -Wextra

# MLX = -framework OpenGL -framework AppKit

# CC = gcc

# SRC_NAME = main.c mlx_img.c

# OBJ_NAME = $(SRC_NAME:.c=.o)

# LIB = ./libft/libft.a

# LIBMLX = ./minilibx_macos/libmlx.a

# all: $(NAME)

# $(LIB):
# 	make -C ./libft

# $(LIBMLX):
# 	make -C ./minilibx_macos

# $(NAME): $(LIB) $(LIBMLX) $(OBJ_NAME)
# 	$(CC) -c $(SRC_NAME)
# 	$(CC) $(MLX) -o $(NAME) $(OBJ_NAME) libft/libft.a minilibx_macos/libmlx.a

# clean:
# 	rm -f $(OBJ_NAME)
# 	make clean -C ./libft

# fclean:
# 	rm -f $(OBJ_NAME)
# 	rm -f $(NAME)
# 	make fclean -C ./libft
# 	make clean -C ./minilibx_macos

# re: fclean all

### COMPILATION ###

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -framework OpenGL -framework AppKit

### EXECUTABLE ###

NAME = fractol

### INCLUDES ###

SRC_NAME = main.c mlx_img.c
SRC_PATH = srcs
OBJ_PATH = objs
HEADER = incl
LIBFT = libft
LIBMLX = minilibx_macos

### OBJECTS ###

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH)/,$(SRC_NAME:.c=.o))


### COLORS ###

NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### RULES ###

all: tmp $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Creating lib files ...$(NOC)"
	@make -C $(LIBFT)
	@make -C $(LIBMLX)
	@$(CC) -w $(CFLAGS) -L $(LIBFT) -o $@ $^ $(MLXFLAGS) -L $(LIBMLX) minilibx_macos/libmlx.a libft/libft.a
	@echo "$(GREEN)Project successfully compiled !$(NOC)"

tmp:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(CFLAGS) -w -I $(HEADER) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(YELLOW)$(notdir $@)... $(GREEN)[Done]$(NOC)"


clean:
	@echo "$(RED)Supressing ...$(NOC)"
	@make clean -C $(LIBFT)
	@make clean -C $(LIBMLX)
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)Object files suppressed$(NOC)"

fclean:
	@echo "$(RED)Supressing ...$(NOC)"
	@rm -rf $(OBJ_PATH)
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)
	@make clean -C $(LIBMLX)
	@echo "$(RED)Files suppressed$(NOC)"

re: fclean all

.phony: all, tmp, re, fclean, clean