NAME := so_long

CC := gcc

CFLAGS := -g3 -Wall -Wextra -Werror -Iheaders/

SOURCE := source/*.c
GETNEXTLINE := get_next_line/*.c

MINILIBX := mlx/
LIBFT := libft/libft.a
PRINTF := ft_printf/libftprintf.a
LIBRARY := -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBFT) $(PRINTF) $(LIBRARY) -o $(NAME)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf
clean:
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf $(NAME)

re: fclean all
