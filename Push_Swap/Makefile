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

SOURCES := accions.c parseo.c sort_utils.c ksort.c sort2.c sort3.c sort4.c sort5.c main.c push_swap.c
OBJECTS := $(SOURCES:.c=.o)
LIBFT := libft/libft.a
LIBRARY := includes/push_swap.h

%.o: %.c $(LIBRARY)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	$(RM) $(OBJECTS)
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
