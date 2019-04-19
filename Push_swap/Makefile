BIN_1 = checker
BIN_2 = push_swap

all: $(BIN_1) $(BIN_2)

$(BIN_1):
	make -C Checker/

$(BIN_2):
	make -C Push_swap/

clean:
	make clean -C Checker/
	make clean -C Push_swap/
	make clean -C Libft/

fclean:
	make fclean -C Checker/
	make fclean -C Push_swap/
	make fclean -C Libft/

re:
	make re -C Checker/
	make re -C Push_swap/
	make re -C Libft/