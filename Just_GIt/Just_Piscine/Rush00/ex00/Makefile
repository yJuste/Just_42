NAME = rush-00

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c rush00.c rush01.c rush02.c rush03.c rush04.c ft_lib.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
