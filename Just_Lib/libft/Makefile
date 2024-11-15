NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_isalnum.c			ft_isalpha.c			ft_isascii.c			\
	ft_isdigit.c			ft_isprint.c			ft_isspace.c			\
	ft_ischar.c											\
	ft_toupper.c			ft_tolower.c			ft_isprime.c			\
	ft_split.c			ft_split_sep.c			ft_strjoin.c			\
	ft_strjoin_sep.c		ft_strdup.c							\
	ft_memcmp.c			ft_memcpy.c			ft_memmove.c			\
	ft_memchr.c			ft_memset.c							\
	ft_strcmp.c			ft_strcspn.c			ft_strlen.c			\
	ft_strchr.c			ft_strrchr.c			ft_strstr.c			\
	ft_substr.c			ft_strcat.c			ft_strcpy.c			\
	ft_strcapitalize.c		ft_strlowcase.c			ft_strupcase.c			\
	ft_strmapi.c			ft_striteri.c							\
	ft_strlcat.c			ft_strlcpy.c			ft_strspn.c			\
	ft_strncmp.c			ft_strncat.c			ft_strncpy.c			\
	ft_strnstr.c			ft_strtolower.c							\
	ft_strtrim.c			ft_strpbrk.c			ft_findchr.c			\
	ft_swap.c			ft_putchar.c			ft_putstr.c			\
	ft_lstsize.c			ft_lstclear.c			ft_lstdelone.c			\
	ft_lstiter.c			ft_lstprint.c			ft_lstlast.c			\
	ft_lstmap.c			ft_lstnew.c			ft_lstadd_back.c		\
	ft_lstadd_front.c										\
	ft_atoi.c			ft_itoa.c			ft_hex.c			\
	ft_bzero.c			ft_malloc.c			ft_calloc.c			\
	ft_realloc.c			ft_find_next_prime.c						\
	ft_dual_digit.c			ft_putnbr.c							\
	ft_lcm.c			ft_pgcd.c			ft_factorial.c			\
	ft_power.c			ft_sqrt.c							\
	ft_range.c			ft_rrange.c							\
	ft_len.c			ft_atoi_base.c			ft_check_base.c			\
	ft_convert_base.c		ft_putnbr_base.c						\
	ft_putchar_fd.c			ft_putendl_fd.c			ft_putnbr_fd.c			\
	ft_putstr_fd.c											\
	ft_get_next_line.c										\

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

s :
	ls -lh $(NAME)

.PHONY: all clean fclean re rf s
