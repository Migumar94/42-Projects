# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 16:23:51 by migumar2          #+#    #+#              #
#    Updated: 2024/09/24 20:11:00 by jholland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3D
CC		:= gcc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code #-g

MLX_DIR	:= ./MLX42
LIB_MLX	:= $(MLX_DIR)/libmlx42.a
HEADERS	:= -I$(MLX_DIR)/include -Iinclude

SRC_FIL	:=	game/cub3d.c utils/get_next_line.c parsing/read_and_check.c parsing/error.c game/frames.c \
			paintings/paint_bg.c loadings/load_walls.c game/rays.c game/hooks.c parsing/check_args.c \
			parsing/check_map.c parsing/fill_content.c utils/utils.c utils/utils2.c utils/split.c
SRC_DIR = $(addprefix src/,$(SRC_FIL))
		
OBJ		:= ${SRC_DIR:.c=.o}

all: $(NAME)

$(LIB_MLX):
	@make -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && echo "Compiling: $(notdir $<)"

$(NAME): $(LIB_MLX) $(OBJ)
	@$(CC) $(OBJ) $(LIB_MLX) $(HEADERS) -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ -o $(NAME) -lm

clean:
	@rm -rf $(OBJ)
	@make clean -C $(MLX_DIR)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIB_MLX)

re: clean all

.PHONY: all, clean, fclean, re