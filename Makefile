CC = gcc
# CC = cc
CFLAGS = -g
# CFLAGS = -Wall -Wextra -Werror
SRCS = $(shell find . -type f -mindepth 2 -name *.c)
OBJS = $(SRCS:%.c=%.o)
NAME = push_swap

all: $(NAME)


$(NAME): $(OBJS)
	$(MAKE) -C libft/
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all