# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 16:23:51 by migumar2          #+#    #+#              #
#    Updated: 2024/03/20 18:31:38 by migumar2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CFLAGS	:= -g -Wextra -Wall -Werror -Wunreachable-code
MLX_DIR = ./MLX42
MLX		:= $(MLX_DIR)/libmlx42.a
CC = gcc

HEADERS	:= -I$(MLX)
SRCS	:= so_long.c check.c check2.c error.c free_map.c get_next_line.c \
		get_next_line_utils.c read_and_check.c so_long_utils.c start_game.c \
		hooks.c moves.c print.c more_utils.c ft_printf.c ft_printf_utils.c
		
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

libmlx:
	@make -C $(MLX_DIR)

%.o: %.c
#	@$(CC) -g -o $@ -c $< && printf "Compiling: $(notdir $<)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX) $(HEADERS) -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
