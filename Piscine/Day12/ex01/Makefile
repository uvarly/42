# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uvarly <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/01 14:46:44 by uvarly            #+#    #+#              #
#    Updated: 2018/11/01 19:34:08 by uvarly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat
FLAGS = -Wall -Wextra -Werror
SRCS = main.c auxiliary_functions.c
INCL = ft_headers.h

all:
	gcc $(FLAGS) -I$(INCL) $(SRCS) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
