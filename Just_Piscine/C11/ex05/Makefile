NAME = do-op

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_do-op.c ft_lib.c ft_operator.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

rf: re
	rm -rf $(OBJS)
	rm -rf $(NAME)

s:
	ls -lh $(NAME)

.PHONY: all clean fclean re rf s
