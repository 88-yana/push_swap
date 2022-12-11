CFLAGS = -Wall -Werror -Wextra
SRCSDIR = src
OBJSDIR = obj
SRCS = src/check/check_arg.c \
		src/check/check_duplicate.c \
		src/check/check_sorted.c \
		src/check/error.c \
		src/list/list.c \
		src/list/operation.c \
		src/list/task.c \
		src/list/write_operation.c \
		src/main/main.c \
		src/make/make_array.c \
		src/make/make_list.c \
		src/shrink/shrink_array.c \
		src/sort/bool.c \
		src/sort/cnt_sort.c \
		src/sort/move_cross.c \
		src/sort/move_stack.c \
		src/sort/simple_sort.c \
		src/sort/sort.c
OBJS = $(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)
LIBFTDIR = libft
NAME = push_swap

all: $(OBJSDIR) $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(OBJS) $(LIBFTDIR)/libft.a -o $(NAME)

$(OBJSDIR):
	mkdir $(shell find $(SRCSDIR) -type d | sed 's/^$(SRCSDIR)/$(OBJSDIR)/g')

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) -rf $(OBJSDIR)
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re