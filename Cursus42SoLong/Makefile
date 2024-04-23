NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror

SOURC	:= control.c ft_init_values.c parseo_map.c read_map.c so_long.c textures.c validate_map.c
SOURCE := $(addprefix ./source/, $(SOURC))
OBJECTS := $(SOURCE:.c=.o)
BON	:= control_bonus.c ft_init_values_bonus.c parseo_map_bonus.c read_map_bonus.c so_long_bonus.c textures_bonus.c validate_map_bonus.c
BONUS := $(addprefix ./source/bonus/, $(BON))
BONUS_OBJ := $(BONUS:.c=.o)
GETNEXTLINE := get_next_line/*.c

MINILIBX := mlx/
LIBFT := libft/libft.a
PRINTF := ft_printf/libftprintf.a
LIBRARY := -lmlx -framework OpenGL -framework AppKit

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(GETNEXTLINE) $(LIBFT) $(PRINTF) $(LIBRARY) -o $(NAME)

bonus: $(BONUS_OBJ) $(LIBFT) $(PRINTF)
	@make -C libft
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(GETNEXTLINE) $(LIBFT) $(PRINTF) $(LIBRARY) -o so_long_bonus

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJ)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf $(NAME) so_long_bonus

re: fclean all

.PHONY: all clean fclean re bonus
