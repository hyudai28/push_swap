#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

#define SORTSIZE 4

typedef struct s_order
{
	int		r_order;
	int		p_order;
	int		node_index;
	int		r_order_cpy;
	int		p_order_cpy;
}				t_order;

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	bool		head;
	int		num;
	int		boundary;
	int		fin;
}			t_stack;


#endif