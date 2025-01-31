NAME = cube

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	cube.c		\
	cube_2.c	\
	cube_3.c	\
	cube_4.c

OBJ = $(SRC:.c=.o)

RESET			= "\033[0m"
GREEN			= "\033[32m"	# Green
RED			= "\033[31m"	# Red
YELLOW			= "\033[33m"	# Jaune

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo $(GREEN)"--- EXECUTABLE ./$(NAME) is ready --- for help : `make help`"$(RESET)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

rf: re
	rm -f $(OBJ)
	rm -f $(NAME)
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

s:
	ls -lh $(NAME)

help:
	@echo $(GREEN)
	@head -n 20 cube.c
	@echo $(RESET)

.PHONY: all clean fclean re rf

