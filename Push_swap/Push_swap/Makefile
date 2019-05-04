NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJ = push_swap.o receive.o validate.o indexation.o head_elements.o instructions.o swap.o push.o rotate.o
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
