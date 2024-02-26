# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 20:05:42 by rde-migu          #+#    #+#              #
#    Updated: 2024/02/26 19:20:33 by rde-migu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = printf.a
SRC = ft_putchar_pf.c ft_printf.c ft_putnbr_pf.c ft_putstr_pf.c ft_putunbr_pf.c ft_puthex_pf.c ft_puthexmayus_pf.c ft_puntero_pf.c
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
