NAME = ft_printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I . -I ../libft/

SRC = ft_printf.c \
	  extract_glyph.c \
	  dispatch.c \
	  printers/cast_char.c \
	  printers/cast_int.c \
	  printers/cast_string.c \
	  printers/cast_uint.c \
	  printers/cast_hex.c \
	  printers/cast_uphex.c \
	  printers/cast_ptr.c

OBJ := $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) run_test

re: fclean all

.PHONY: all clean fclean re
