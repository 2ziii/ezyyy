NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
		ft_atoi.c \
		ft_split.c \
		validate_args.c \
		insert_node.c \
		check_duplication.c \
		free_node.c \
		get_node_rank.c \
		check_sort.c \
		rules_swap.c \
		rules_push.c \
		rules_rotate.c \
		rules_rev_rotate.c \
		sort.c \
		radix_sort.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re