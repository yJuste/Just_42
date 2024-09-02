NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c utils/ft_append_buffer.c utils/ft_append_seg_buffer.c utils/ft_atoi.c utils/ft_convert_hundreds.c utils/ft_convert_number.c utils/ft_convert_tens.c utils/ft_convert_units.c utils/ft_get_seg.c utils/ft_proc_seg.c utils/ft_read_number.c utils/ft_strlen.c utils/ft_strncpy.c utils/ft_write.c
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
