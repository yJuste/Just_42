NAME = ft_tail

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_tail.c ft_tail_next.c ft_lib_tail.c ft_error_tail.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

rf : re
	@rm -f $(OBJS)
	@rm -f $(NAME)

s:
	ls -lh $(NAME)

.PHONY: all clean fclean re
