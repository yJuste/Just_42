NAME = ft_cat

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_cat.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

rf : re
	rm -f $(OBJS)
	rm -f $(NAME)

s:
	ls -lh $(NAME)

.PHONY: all clean fclean re
