# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 20:03:40 by migumar2          #+#    #+#              #
#    Updated: 2024/07/31 21:44:52 by migumar2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Nombre de la biblioteca
NAME = philo

# Archivos fuente
SRCS = philosopher.c utils.c philo_life.c philo_life2.c
		 


# Archivos objeto
OBJS = $(SRCS:.c=.o)
# Flags de compilación
CFLAGS = -Wall -Wextra -Werror
CC= gcc
# Regla principal
all: $(NAME)
# Regla para compilar los archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para construir la biblioteca
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
# Regla para limpiar los archivos objeto y la biblioteca
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

# Regla para reconstruir todo
re: fclean all

.PHONY: all clean fclean re
