CC = cc

SRC = ft_printf.c \
      utils.c \
      2utils.c 

INC = printf.h

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = ft_printf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
