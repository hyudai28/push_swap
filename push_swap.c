#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>

//atoi!!!!!!!!!!!!!!!

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	bool			head;
	int				num;
}			t_stack;


void	sa(t_stack *a, t_stack *b)
{
	t_stack	*a_fst2sec;
	t_stack *a_sec2fst;

	a_fst2sec = a;
	a_fst2sec = a_fst2sec->next;
	a_sec2fst = a_fst2sec->next;
	a->next = a_sec2fst;
	a_fst2sec->prev = a_sec2fst;
	a_fst2sec->next = a_sec2fst->next;
	a_sec2fst->prev = a;
	a_sec2fst->next = a_fst2sec;
	write(1, "sa\n", 2);
}


void	sb(t_stack *a, t_stack *b)
{
	t_stack	*b_fst2sec;
	t_stack *b_sec2fst;

	b_fst2sec = b;
	b_fst2sec = b_fst2sec->next;
	b_sec2fst = b_fst2sec->next;
	b->next = b_sec2fst;
	b_fst2sec->prev = b_sec2fst;
	b_fst2sec->next = b_sec2fst->next;
	b_sec2fst->prev = b;
	b_sec2fst->next = b_fst2sec;
	write(1, "sb\n", 2);
}

void	ss(t_stack *a, t_stack *b)
{
	t_stack	*a_fst2sec;
	t_stack *a_sec2fst;
	t_stack	*b_fst2sec;
	t_stack *b_sec2fst;

	a_fst2sec = a;
	a_fst2sec = a_fst2sec->next;
	a_sec2fst = a_fst2sec->next;
	a->next = a_sec2fst;
	a_fst2sec->prev = a_sec2fst;
	a_fst2sec->next = a_sec2fst->next;
	a_sec2fst->prev = a;
	a_sec2fst->next = a_fst2sec;
	b_fst2sec = b;
	b_fst2sec = b_fst2sec->next;
	b_sec2fst = b_fst2sec->next;
	b->next = b_sec2fst;
	b_fst2sec->prev = b_sec2fst;
	b_fst2sec->next = b_sec2fst->next;
	b_sec2fst->prev = b;
	b_sec2fst->next = b_fst2sec;
	write(1, "ss\n", 3);
}

void	ra(t_stack *a, t_stack *b)
{
	
}

void	rb(t_stack *a, t_stack *b)
{
	
}

void	rr(t_stack *a, t_stack *b)
{
	
}


void	rra(t_stack *a, t_stack *b)
{
	
}

void	rrb(t_stack *a, t_stack *b)
{
	
}

void	rrr(t_stack *a, t_stack *b)
{
	
}

void	pa(t_stack *a, t_stack *b)
{
	
}

void	pb(t_stack *a, t_stack *b)
{
	
}






t_stack	*stack_setup(void)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	b->head = 1;
	b->next = NULL;
	b->prev = NULL;
	b->num = 0;
	return (b);
}


t_stack	*make_list(int argc, char **argv)
{
	t_stack	*head;
	t_stack	*now;
	t_stack	*new;
	int		struct_count;

	head = malloc(sizeof(t_stack));
	head->head = 1;
	head->next = NULL;
	head->prev = NULL;
	head->num = 0;
	now = head;
	struct_count = 0;
	while (++struct_count < argc)
	{
		new = malloc(sizeof(t_stack));
		new->prev = now;
		new->next = head;
		new->num = atoi(argv[struct_count]);
		new->head = 0;
		now->next = new;
		now = now->next;
	}
	now = head;
	return (head);
}


void	print_node(t_stack *node, int node_num, int argc)
{
	int node_index;
	char stack_type;

	if (node_num)
		stack_type = 'a';
	else
		stack_type = 'b';
	node_index = 1;
	node = node->next;
	while (!node->head)
	{
		printf("[%c]node[%d] = [%d]\n", stack_type, node_index, node->num);
		node_index++;
		node = node->next;
	}
	puts("print fin");
}

void	ps_error_check(int argc, char **argv)
{
	int	num_tmp;
	int	arg_i;

	if (argc < 2)
	{
		exit(1);
	}
	num_tmp = 0;
	arg_i = 0;
	while (arg_i < argc)
	{
		num_tmp = atoi(argv[arg_i]);
		arg_i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack *a_stack;
	t_stack *b_stack;

	ps_error_check(argc, argv);
	b_stack = stack_setup();
	a_stack = make_list(argc, argv);
	print_node(a_stack, 1, argc);
	sa(a_stack, b_stack);
	print_node(a_stack, 1, argc);
}