NAME = just_lib.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = *.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) -I $(CFLAGS) -c $(CFLAGS) $(SRC)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

rf : re
	rm -f $(OBJ)
	rm -f $(NAME)

s:	
	ls -lh $(NAME)

.PHONY: all clean fclean re rf s
