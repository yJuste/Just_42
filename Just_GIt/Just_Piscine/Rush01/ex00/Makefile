NAME = rush-01

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c rush-01.c rush-02.c rush-03.c rush-04.c ft_lib.c ft_lib2.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

rf : re fclean

.PHONY: all clean fclean re rf
