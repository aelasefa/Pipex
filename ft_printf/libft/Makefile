
NAME:= libft.a

SRCS := ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_strlen.c ft_strlcpy.c \
		ft_strncmp.c ft_split.c

OBJS := $(SRCS:.c=.o)


AR = ar rcs

CC = cc

CFLAGS := -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
		$(AR) $(NAME) $(OBJS)

%.o : %.c
		$(CC) $(CFLAGS) -c  $< -o $@

clean :
	rm -f $(OBJS) $(OBJSB)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY 	: clean
