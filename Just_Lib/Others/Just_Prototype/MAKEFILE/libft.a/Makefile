NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_putchar.c ft_putstr.c ft_strlen.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

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
