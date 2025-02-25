# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 18:58:53 by tfournie          #+#    #+#              #
#    Updated: 2025/02/25 13:14:51 by tfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -I./ft_printf_42 -I./libft_git

NAME = push_swap

# MAIN = push_swap.c

SRC = push_swap_utils.c \
	  push_swap_inst.c \
	  error_check.c \
	  algo.c \
	  algo_dure.c \
	  algo_utils.c \
	  ft_sort.c \
	  algo_cost_ab.c \
	  algo_cost.c \
	  algo_cost_ab_utils.c \
	  push_swap.c \

OBJ = $(SRC:.c=.o)

LIB_DIR_P = ft_printf_42
LIB_PATH_P = -L$(LIB_DIR_P)

LIB_DIR_L = libft_git
LIB_PATH_L = -L$(LIB_DIR_L)

all: $(NAME)

$(NAME): $(OBJ) $(LIB_DIR_P)/libftprintf.a $(LIB_DIR_L)/libft.a Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_PATH_P) -lftprintf $(LIB_PATH_L) -lft
	echo "$(NAME) created!"

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_DIR_P)/libftprintf.a: FORCE
	$(MAKE) -C $(LIB_DIR_P)/

$(LIB_DIR_L)/libft.a: FORCE
	$(MAKE) -C $(LIB_DIR_L)/

clean:
	rm -f $(OBJ)
	rm -f $(LIB_DIR_P)/*.o
	rm -f $(LIB_DIR_L)/*.o
	echo "Object files cleaned!"

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_DIR_P)/libftprintf.a
	rm -f $(LIB_DIR_L)/libft.a
	echo "$(NAME) removed!"

FORCE:

re: fclean all

.PHONY : all clean fclean re