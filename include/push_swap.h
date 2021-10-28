#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

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
	bool			head;
	int				num;
	int				boundary;
	int				fin;
}			t_stack;

//push_swap
int		do_swap_2(t_stack *node, int list_flag);
int		swap_3(t_stack *target, int list_flag);
void	do_swap_over_5(t_stack *a, t_stack *b);
int		do_swap_over_6(t_stack *a, t_stack *b, int num_size);

//ps_3case
int		swap3_case1(t_stack *target, int list_flag);
int		swap3_case2(t_stack *target, int list_flag);
int		swap3_case3(t_stack *target, int list_flag);
int		swap3_case4(t_stack *target, int list_flag);
int		swap3_case5(t_stack *target, int list_flag);

//ps_commands
int		sa(t_stack *a);
int		sb(t_stack *b);
int		ss(t_stack *a, t_stack *b);
int		ra(t_stack *a, int print);
int		rb(t_stack *b, int print);
int		rr(t_stack *a, t_stack *b);
int		rra(t_stack *a, int print);
int		rrb(t_stack *b, int print);
int		rrr(t_stack *a, t_stack *b);
int		pa(t_stack *a, t_stack *b);
int		pb(t_stack *a, t_stack *b);

//ary_sort
void	node_to_ary(t_stack *a, int size, int *ary);
void	qsort_swap_number(int *ary, int i, int j);
void	ft_qsort(int *ary, int left, int right);
int		get_median(t_stack *a, int size);
void	sorted_check(int *ary, int argc);

//ft_atoi
long	ft_atoi(const char *str);

//libft
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isspace(int c);
int		ft_isdigit(int c);

//ps_list_utils
int		get_node_count(t_stack *node);
int		node_count(t_stack *node);
int		count_stack_size(t_stack *stack);

//ps_make_list
void	stack_next(t_stack *move);
t_stack	*stack_setup(void);
t_stack	*make_list(int argc, char **argv);

//ps_utils
void	error_exit(void);
void	arg_error(long num, char *argv);
void	ps_error_check(int argc, char **argv);
int		serch_min_num(t_stack *target);
void	ary_check(t_stack *a, int num_size);

//ps_over6case
int		half_a_to_b(t_stack *a, t_stack *b, int num_size, int sort_fin);
int		b_quick_sort(t_stack *a, t_stack *b);
int		allsort(t_stack *a, t_stack *b);
void	ps_b_qsort(t_stack *a, t_stack *b);

int		opt_is_nextfin(t_stack *a, int not_first);
void	opt_is_notfirst(t_stack *a, int ra_index);
int		all_to_b(t_stack *a, t_stack *b);
int		unsorted_num(t_stack *node);
void	print_node(t_stack *node, int node_num);

#endif
