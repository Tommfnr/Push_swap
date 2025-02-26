# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 14:41:46 by tfournie          #+#    #+#              #
#    Updated: 2025/01/28 19:33:38 by tfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c \
      ft_printf_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) Makefile
	ar rcs $(NAME) $(OBJ)
	echo "Library $(NAME) created!"

%.o: %.c printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	echo "Object files cleaned!"

fclean: clean
	rm -f $(NAME)
	echo "Library $(NAME) removed!"

re: fclean all

.PHONY : all clean fclean re
