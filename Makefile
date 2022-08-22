CC = cc
# CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c
OBJS = $(SRCS:%.c=%.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY : all clean fclean re
