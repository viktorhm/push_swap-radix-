
NAME		= push_swap

SRCS		= $(wildcard srcs/*.c)

OBJS		= $(SRCS:.c=.o)

CC		= cc
CFLAGS		= -Wall -Wextra -Werror -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

