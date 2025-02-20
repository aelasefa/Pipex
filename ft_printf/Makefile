
NAME := libftprintf.a

SRCS := print_hex.c print_unsigned.c ft_printf.c print_add.c \
	print_int.c print_char.c print_string.c

OBJS := $(SRCS:%.c=%.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

LIBFT = libft.a
LIBFTDIR = libft
AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) $(NAME)
		$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make -C $(LIBFTDIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)
re: fclean all

.PHONY : clean
