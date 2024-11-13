SRC = *.c
NAME = libft.a
OBJ = ${SRC:.c=.o}
FLAGS = -Wall -Werror -Wextra

all : $(NAME)
	@true

$(NAME) :
	gcc -I $(FLAGS) -c $(FLAGS) $(SRC)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -f $(NAME)

fclean : clean
	rm -rf $(OBJ)

dev:
	make fclean;cd ../libft-unit-test; make f;cd ../libft; make fclean

re : fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY : all clean fclean re dev so
