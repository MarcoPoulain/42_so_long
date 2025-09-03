NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = app_core/main.c \
	  gnl/get_next_line.c \
	  gnl/get_next_line_utils.c \
	  app_core/map_parsing/map_arr.c \
	  app_core/map_parsing/map_utils.c \
	  app_core/map_parsing/map_checker.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/ft_printf.a

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11

INCLUDES = -Imlx -Iheaders -Ilibft -Ift_printf -Ignl

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(NAME): $(LIBFT) $(PRINTF) $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC) headers/*.h $(LIBFT_DIR) $(PRINTF_DIR)

.PHONY: all clean fclean re norm
