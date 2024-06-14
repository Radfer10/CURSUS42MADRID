# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 23:21:23 by rde-migu          #+#    #+#              #
#    Updated: 2024/06/14 20:59:39 by rde-migu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := gcc

CFLAGS := -Wall -Wextra -Werror -g3 -fsanitize=address

# Archivos fuentes y objetos
SOURCES := src/accions.c movements/swap.c movements/push.c movements/rotate.c movements/reverse_rotate.c src/utils_parseo.c src/check_parseo.c src/parseo.c src/sort_utils.c src/ksort.c src/sort2.c src/sort3.c src/sort4.c src/sort5.c src/main.c src/push_swap.c
OBJECTS := $(SOURCES:.c=.o)

# Librerías y rutas de inclusión
LIBFT := libft/libft.a
INCLUDES := -Iincludes -Ilibft

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

# Regla para compilar el ejecutable
$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

# Regla para compilar la librería libft
$(LIBFT):
	make -C libft

# Regla para limpiar los archivos objeto
clean:
	$(RM) $(OBJECTS)
	make clean -C libft

# Regla para limpiar todo
fclean: clean
	make fclean -C libft
	rm -f $(NAME)

# Regla para recompilar todo
re: fclean all

.PHONY: all clean fclean re
