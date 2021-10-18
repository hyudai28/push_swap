NAME := push_swap

CC := gcc
CFLAGS := -Wall -Werror -Wextra
SOURCE_DIR = src

SRCS := push_swap.c
#SRCS = $(SOURCE_DIR)/


OBJS := ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAG) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re