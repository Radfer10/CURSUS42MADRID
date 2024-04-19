NAME := so_long

CC := gcc

CFLAGS := -g3 -Wall -Wextra -Werror -Iheaders/

SOURCE := source/*.c
GETNEXTLINE := get_next_line/*c
LIBRARY := -lmlx -framework OpenGL -framework AppKit
MINILIBX := mlx/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all
