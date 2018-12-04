# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uvarly <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 14:22:01 by uvarly            #+#    #+#              #
#    Updated: 2018/10/30 17:40:24 by uvarly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft.a
SRCS = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c \
	   ./srcs/ft_strlen.c ./srcs/ft_swap.c 
INCL = ./includes/*.h
OBJ = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all: $(LIB)

$(LIB):
	gcc -c $(SRCS) -I $(INCL)
	ar rc $(LIB) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f ./includes/headers.h.gch

fclean: clean
	rm -f $(LIB)

re:	fclean all
