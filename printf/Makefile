NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
CLEAN = rm -Rf
SRC = ft_printf.c ft_printf_utils.c
OBJS = $(SRC:.c=.o)
all: $(NAME)
$(NAME):$(OBJS)
	@ar rcs $(NAME) $(OBJS)
%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re