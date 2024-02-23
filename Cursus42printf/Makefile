# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-migu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 20:05:42 by rde-migu          #+#    #+#              #
#    Updated: 2024/02/23 15:10:56 by rde-migu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = printf.a
SRC = ft_putchar_pf.c ft_printf.c
OBJ = $(SRC:.c=.o)
INCLUDE = printf.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: flcen all

.PHONY: clean fclean re
