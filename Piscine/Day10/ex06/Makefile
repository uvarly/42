# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uvarly <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 19:00:26 by uvarly            #+#    #+#              #
#    Updated: 2018/10/30 12:47:44 by uvarly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRC = ./srcs/do_op.c ./srcs/ft_add.c ./srcs/ft_sub.c ./srcs/ft_mul.c \
	  ./srcs/ft_div.c ./srcs/ft_mod.c ./srcs/ft_putchar.c ./srcs/ft_putstr.c \
	  ./srcs/ft_putnbr.c ./srcs/ft_atoi.c

FLAGS = -Wall -Wextra -Werror

all:
	gcc $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)
