NAME = fdf
LIB = libft/libft.a
INCL = includes/fdf.h
FLAGS = -Wall -Wextra -Werror

OBJ = sources/fdf.o sources/valid.o sources/parser.o \
	sources/print_map.o sources/rotation.o

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
#	@make -C libft
	@cc $(OBJ) $(LIB) -lmlx -framework OpenGL -framework AppKit -o $@

edit: $(OBJ)
	@gcc $(FLAGS) -o $(OBJ)

%.o: %.c $(INCL)

clean:
#	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
#	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all