CC = cc
# CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c
OBJS = $(SRCS:%.c=%.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME)
bonus:
	make WITH_BONUS=1
clean:
	$(RM) $(OBJS) $(LIST:%.c=%.o)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY : all clean fclean re
