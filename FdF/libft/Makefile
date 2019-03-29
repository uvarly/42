# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uvarly <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 15:29:06 by uvarly            #+#    #+#              #
#    Updated: 2019/02/24 09:30:16 by pcorlys-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror

OBJ = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
      ft_isdigit.o ft_isprint.o ft_itoa.o ft_lstadd.o ft_lstdel.o \
      ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_lstpushback.o \
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
	@gcc $(FLAGS) -o $(OBJ)

ft_atoi.o: libft.h
ft_bzero.o: libft.h get_next_line.h
ft_isalnum.o: libft.h get_next_line.h
ft_isalpha.o: libft.h get_next_line.h
ft_isascii.o: libft.h get_next_line.h
ft_isdigit.o: libft.h get_next_line.h
ft_isprint.o: libft.h get_next_line.h
ft_itoa.o: libft.h get_next_line.h
ft_lstadd.o: libft.h get_next_line.h
ft_lstdel.o: libft.h get_next_line.h
ft_lstdelone.o: libft.h get_next_line.h
ft_lstiter.o: libft.h get_next_line.h
ft_lstmap.o: libft.h get_next_line.h
ft_lstnew.o: libft.h get_next_line.h
ft_lstpushback.o: libft.h get_next_line.h
ft_lstpushfront.o: libft.h get_next_line.h
ft_memalloc.o: libft.h get_next_line.h
ft_memccpy.o: libft.h get_next_line.h
ft_memchr.o: libft.h get_next_line.h
ft_memcmp.o: libft.h get_next_line.h
ft_memcpy.o: libft.h get_next_line.h
ft_memdel.o: libft.h get_next_line.h
ft_memmove.o: libft.h get_next_line.h
ft_memset.o: libft.h get_next_line.h
ft_numlen.o: libft.h get_next_line.h
ft_putchar.o: libft.h get_next_line.h
ft_putchar_fd.o: libft.h get_next_line.h
ft_putendl.o: libft.h get_next_line.h
ft_putendl_fd.o: libft.h get_next_line.h
ft_putnbr.o: libft.h get_next_line.h
ft_putnbr_fd.o: libft.h get_next_line.h
ft_putstr.o: libft.h get_next_line.h
ft_putstr_fd.o: libft.h get_next_line.h
ft_sortinttab.o: libft.h get_next_line.h
ft_strcat.o: libft.h get_next_line.h
ft_strchr.o: libft.h get_next_line.h
ft_strclr.o: libft.h get_next_line.h
ft_strcmp.o: libft.h get_next_line.h
ft_strcpy.o: libft.h get_next_line.h
ft_strdel.o: libft.h get_next_line.h
ft_strdup.o: libft.h get_next_line.h
ft_strequ.o: libft.h get_next_line.h
ft_striter.o: libft.h get_next_line.h
ft_striteri.o: libft.h get_next_line.h
ft_strjoin.o: libft.h get_next_line.h
ft_strlcat.o: libft.h get_next_line.h
ft_strlen.o: libft.h get_next_line.h
ft_strmap.o: libft.h get_next_line.h
ft_strmapi.o: libft.h get_next_line.h
ft_strncat.o: libft.h get_next_line.h
ft_strncmp.o: libft.h get_next_line.h
ft_strncpy.o: libft.h get_next_line.h
ft_strndup.o: libft.h get_next_line.h
ft_strnequ.o: libft.h get_next_line.h
ft_strnew.o: libft.h get_next_line.h
ft_strnstr.o: libft.h get_next_line.h
ft_strrchr.o: libft.h get_next_line.h
ft_strsplit.o: libft.h get_next_line.h
ft_strstr.o: libft.h get_next_line.h
ft_strsub.o: libft.h get_next_line.h
ft_strtrim.o: libft.h get_next_line.h
ft_sqrt.o: libft.h get_next_line.h
ft_tolower.o: libft.h get_next_line.h
ft_toupper.o: libft.h get_next_line.h
get_next_line.o: libft.h get_next_line.h

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
