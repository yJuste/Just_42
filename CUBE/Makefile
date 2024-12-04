NAME = cube

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

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
	@echo $(GREEN)"--- EXECUTABLE ./$(NAME) is ready ---"$(RESET)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

rf: re
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

s:
	ls -lh $(NAME)

help:
	head -n 18 cube.c

.PHONY: all clean fclean re rf

