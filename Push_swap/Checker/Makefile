NAME = checker
CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJ = checker.o receive.o validate.o swap.o push.o rotate.o
INC = checker.h
LIB = ../Libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIB)

$(OBJ): %.o: %.c
	@$(CC) $(FLAGS) -c $< -I $(INC) -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
