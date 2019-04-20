NAME = checker
CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJ = checker.o receive.o validate.o swap.o push.o rotate.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ -c $(OBJ)

edit: $(OBJ)
	@$(CC) -o $(FLAGS) edit $(OBJ)

$(OBJ): checker.h

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
