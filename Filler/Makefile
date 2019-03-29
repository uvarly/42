NAME = uvarly.filler
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB = libft
OBJ =	sources/filler.o \
		sources/utility_functions.o \
		sources/parsing_functions.o \
		sources/resolving_functions.o
INC = includes/filler.h

all : $(NAME)

$(NAME): $(OBJ)
#	@make -C $(LIB)
	@$(CC) $(FLAGS) $(OBJ) $(LIB)/libft.a -o $(NAME)

edit:
	@$(CC) -o $(FLAGS) edit $(OBJ)

$(OBJ): includes/filler.h

clean:
	@rm -f $(OBJ)
#	@make clean -C $(LIB)

fclean: clean
	@rm -f $(NAME)
#	@make fclean -C $(LIB)

re: fclean all