CH = checker
PS = push_swap

all: $(CH) $(PS)

$(CH):
	make -C Checker/

$(PS):
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