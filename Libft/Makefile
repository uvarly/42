# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uvarly <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 15:29:06 by uvarly            #+#    #+#              #
#    Updated: 2019/04/17 18:30:59 by uvarly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJ = ft_atoi.o ft_bzero.o ft_isint.o ft_isnum.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
      ft_isdigit.o ft_isprint.o ft_itoa.o ft_lstprepend.o ft_lstappend.o ft_lstdel.o \
      ft_lstdelone.o ft_lstfree.o ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_lstpresent.o ft_lstpushback.o \
      ft_lstpushfront.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
      ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_numlen.o ft_putchar.o \
      ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o \
      ft_putstr.o ft_putstr_fd.o ft_sortinttab.o ft_strcat.o ft_strchr.o ft_strclr.o \
      ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o \
      ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o \
      ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o  ft_strndup.o\
      ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strsplit.o \
      ft_strstr.o ft_strsub.o ft_strtrim.o ft_sqrt.o ft_tolower.o ft_toupper.o \
	  get_next_line.o

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc libft.a $(OBJ)

edit: $(OBJ)
	@$(CC) -o $(FLAGS) edit $(OBJ)

$(OBJ): libft.h

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
