NAME := pipex

CC := cc -g3

CFLAGS := -Wall -Wextra -Werror

SRC := main.c ft_strjoin.c check_input.c pipex_utils.c

OBJS := $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ft_printf
	$(CC) $(CFLAGS) $(SRC)  ft_printf/libftprintf.a -o $(NAME)

clean :
	make -C ft_printf clean
	rm -rf $(OBJS)

fclean : clean
	make -C ft_printf fclean
	rm -rf $(NAME)

re : fclean all
