# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uvarly <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 15:29:06 by uvarly            #+#    #+#              #
#    Updated: 2018/12/05 12:18:52 by uvarly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c ft_isprint.c ft_memset.c ft_strlcat.c ft_strrchr.c \
	   ft_bzero.c ft_memccpy.c ft_strcat.c ft_strlen.c ft_strstr.c \
	   ft_isalnum.c ft_memchr.c ft_strchr.c ft_strncat.c ft_tolower.c \
	   ft_isalpha.c ft_memcmp.c ft_strcmp.c ft_strncmp.c ft_toupper.c \
	   ft_isascii.c ft_memcpy.c ft_strcpy.c ft_strncpy.c ft_isdigit.c \
	   ft_memmove.c ft_strdup.c ft_strnstr.c

OBJ = ft_atoi.o ft_isprint.o ft_memset.o ft_strlcat.o ft_strrchr.o \
		ft_bzero.o ft_memccpy.o ft_strcat.o ft_strlen.o ft_strstr.o \
		ft_isalnum.o ft_memchr.o ft_strchr.o ft_strncat.o ft_tolower.o \
		ft_isalpha.o ft_memcmp.o ft_strcmp.o ft_strncmp.o ft_toupper.o \
		ft_isascii.o ft_memcpy.o ft_strcpy.o ft_strncpy.o ft_isdigit.o \
		ft_memmove.o ft_strdup.o ft_strnstr.o

all: $(NAME)

$(NAME):
	@gcc -I libft.h $(FLAGS) -c $(SRC)
	@ar rc libft.a $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
