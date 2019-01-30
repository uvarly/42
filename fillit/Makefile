NAME = fillit
INCL = fillit.c figure_reset.c figure_offset.c figure_standartization.c figure_validation.c fill_map.c get_input.c scale_adjustment.c utility.c
OBJ = fillit.o figure_reset.o figure_offset.o figure_standartization.o figure_validation.o fill_map.o get_input.o scale_adjustment.o utility.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc $(FLAGS) -c $(INCL)
	gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	rm -f *.o
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all