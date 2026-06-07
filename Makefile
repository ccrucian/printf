CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC_DIR = srcs

SRCS = ft_printf.c \
      utils.c \
      utils_2.c \
	  utils_3.c

INC = ft_printf.h

OBJ = $(SRCS:.c=.o)

BONUS_DIR = bonus

SRCS_BONUS = $(BONUS_DIR)/dispatch_bonus.c \
		$(BONUS_DIR)/handle_p_bonus.c \
		$(BONUS_DIR)/handle_u_bonus.c \
		$(BONUS_DIR)/handle_x_bonus.c \
		$(BONUS_DIR)/handle_c_s_bonus.c \
		$(BONUS_DIR)/handle_d_i_bonus.c \
		$(BONUS_DIR)/hex_utils_bonus.c \
		$(BONUS_DIR)/number_utils_bonus.c \
		$(BONUS_DIR)/string_utils_bonus.c \
		$(BONUS_DIR)/padding_bonus.c \
		$(BONUS_DIR)/parser_bonus.c \
		$(BONUS_DIR)/parsing_bonus.c \
		$(BONUS_DIR)/start_bonus.c \
		
OBJ_BONUS = $(SRCS_BONUS:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_BONUS)
	rm -f $(NAME)
	ar rcs $(NAME) $(OBJ_BONUS)	

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
 
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
