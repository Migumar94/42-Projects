
# Nombre de la biblioteca
NAME = pipex
NAME2 = checker
# Archivos fuente
SRCS = ft_split.c pipex.c pipex_utils.c pipex_extras.c ft_strrchr.c error.c ft_strtrim.c exec.c
		 


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
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(NAME2)

# Regla para reconstruir todo
re: fclean all

.PHONY: all clean fclean re 
