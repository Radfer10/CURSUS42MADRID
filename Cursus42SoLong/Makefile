NAME := so_long

CC := gcc

CFLAGS := -g3 -Wall -Wextra -Werror -Iheaders/

SOURCE := source/*.c
GETNEXTLINE := get_next_line/*.c

MINILIBX := mlx/
LIBFT := libft/libft.a
LIBRARY := -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBFT) $(LIBRARY) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all
