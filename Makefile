NAME := push_swap

CC := gcc
#CFLAGS := -Wall -Wextra -Werror
SOURCE_DIR = src
MINILIB_DIR = mini_libft
OBJDIR = obj

SRCS := $(SOURCE_DIR)/push_swap.c
SRCS += $(SOURCE_DIR)/ps_3case.c
SRCS += $(SOURCE_DIR)/ps_commands.c
SRCS += $(SOURCE_DIR)/ps_list_utils.c
SRCS += $(SOURCE_DIR)/ps_utils.c
SRCS += $(SOURCE_DIR)/libft_utils.c

OBJS := ${SRCS:.c=.o}


all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all
N = 100
ARG := $(shell python3 -c 'import random; print(*random.sample([i for i in range(-999, 999)], $(N)))')

# # There may be duplicates.
# ARG := $(shell python3 -c 'import random; print(*([random.randrange(-2147483648, 2147483647) for i in range($(N))]))')

# ARG := $(shell jot -r -s " " 100 -2147483648 2147483647)

test: all
		@echo $(ARG) | tee arg
		@echo
		@./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo
		@./push_swap $(ARG) | wc -l | bc
		@echo

.PHONY: all clean fclean re