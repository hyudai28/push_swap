#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
//# include "./../libft/libft.h"

# define SORTSIZE 4
# define LIST_A 0
# define LIST_B 1

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

//ps_3case
int	swap_3(t_stack *target, int list_flag);
int	swap3_case1(t_stack *target, int list_flag);
int	swap3_case2(t_stack *target, int list_flag);
int	swap3_case3(t_stack *target, int list_flag);
int	swap3_case4(t_stack *target, int list_flag);
int	swap3_case5(t_stack *target, int list_flag);

//ps_commands
int	sa(t_stack *a);
int	sb(t_stack *b);
int	ss(t_stack *a, t_stack *b);
int	ra(t_stack *a, int print);
int	rb(t_stack *b, int print);
int	rr(t_stack *a, t_stack *b);
int	rra(t_stack *a, int print);
int	rrb(t_stack *b, int print);
int	rrr(t_stack *a, t_stack *b);
int	pa(t_stack *a, t_stack *b);
int	pb(t_stack *a, t_stack *b);

//ps_list_utils
void	stack_next(t_stack *move);
t_stack	*stack_setup(void);
t_stack	*make_list(int argc, char **argv);
void	print_node(t_stack *node, int node_num, int argc);
void	restore_node_ptr(t_stack *node);
int	get_node_count(t_stack *node);

//ps_utils
void	ps_error_check(int argc, char **argv);
int	serch_min_num(t_stack *target);

//libft

//int    ft_atoi(const char *nptr);
long    ft_atoi(const char *nptr);
int	ft_isspace(int c);
int	ft_isdigit(int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);


#endif