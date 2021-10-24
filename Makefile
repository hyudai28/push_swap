NAME := push_swap

CC := gcc
CFLAGS := -Wall -Werror -Wextra
SOURCE_DIR = src
MINILIB_DIR = mini_libft

SRCS := $(SOURCE_DIR)/push_swap.c
SRCS += $(SOURCE_DIR)/ps_3case.c
SRCS += $(SOURCE_DIR)/ps_commands.c
SRCS += $(SOURCE_DIR)/ps_list_utils.c
SRCS += $(SOURCE_DIR)/ps_utils.c


OBJS := ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
		$(CC) $(CFLAGS) ./libft/libft.a -o $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAG) -c $< -o $@

clean:
		rm -f $(OBJS)
		make clean -C libft

fclean: clean
		rm -rf $(NAME)
		make fclean -C libft

re: fclean all

.PHONY: all clean fclean re