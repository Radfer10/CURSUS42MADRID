# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 23:21:23 by rde-migu          #+#    #+#              #
#    Updated: 2024/05/28 23:45:05 by rde-migu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := gcc

CFLAGS := -Wall -Wextra -Werror

SOURC	:= accions.c parseo.c ksort.c sort2.c sort3.c sort4.c sort5.c main.c push_swap.c 
SOURCE := $(addprefix ./source/, $(SOURC))
OBJECTS := $(SOURCE:.c=.o)
LIBFT := libft/libft.a
LIBRARY := -lmlx -framework OpenGL -framework AppKit

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(GETNEXTLINE) $(LIBFT) $(PRINTF) $(LIBRARY) -o $(NAME)


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