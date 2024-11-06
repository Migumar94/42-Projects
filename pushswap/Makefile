
# Nombre de la biblioteca
NAME = push_swap
NAME2 = checker
# Archivos fuente
SRCS = checklist.c cost.c create_stack.c error.c free_list.c ft_atoi.c \
		ft_split.c ft_strdup.c ft_strlen.c ft_substr.c moves.c moves2.c \
		moves3.c push.c pushswap_utils.c pushswap.c re_rotate.c rotate.c \
		sort_all.c sort_three.c swap.c target.c 
		 

BSRCS = checker_bonus.c get_next_line.c get_next_line_utils.c checklist.c create_stack.c \
		error.c free_list.c ft_atoi.c ft_split.c pushswap_utils.c push.c re_rotate.c rotate.c\
		swap.c ft_substr.c ft_strdup.c moves.c moves2.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
# Flags de compilación
CFLAGS = -Wall -Wextra -Werror
CC= gcc
# Regla principal
all: $(NAME)
bonus: checker
# Regla para compilar los archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para construir la biblioteca
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
checker: $(BOBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME2)
# Regla para limpiar los archivos objeto y la biblioteca
clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(NAME2)

# Regla para reconstruir todo
re: fclean all

.PHONY: all clean fclean re bonus
