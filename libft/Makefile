
# Nombre de la biblioteca
NAME = libft.a

# Archivos fuente
SRCS = ft_atoi.c ft_bzero.c  ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_tolower.c ft_toupper.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 
		 

BSRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
# Flags de compilación
CFLAGS = -Wall -Wextra -Werror

# Regla principal
all: $(NAME)

# Regla para compilar los archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para construir la biblioteca
$(NAME): $(OBJS)
	ar rcs $@ $^
bonus: $(OBJS) $(BOBJS)
	ar rcs $(NAME) $^
# Regla para limpiar los archivos objeto y la biblioteca
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

# Regla para reconstruir todo
re: fclean all

.PHONY: all clean fclean re
