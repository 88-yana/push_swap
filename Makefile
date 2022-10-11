CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(shell find . -type f -mindepth 2 -name *.c)
OBJS = $(SRCS:%.c=%.o)
NAME = push_swap

all: $(NAME)

test:
	@bash test.sh

$(NAME): $(OBJS)
	$(MAKE) -C libft/
	$(CC) $(CFLAGS) $(RLFLAGS) $(OBJS) libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(RLFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all