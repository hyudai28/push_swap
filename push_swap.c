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
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
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

void	ra(t_stack *a, t_stack *b, int print)
{
	t_stack	*fst2last;
	t_stack	*lst2sec;

	fst2last = a->next;
	lst2sec = a->prev;
	a->next->next->prev = a;
	a->next = a->next->next;
	fst2last->next = a;
	fst2last->prev = a->prev;
	lst2sec->next = fst2last;
	a->prev = fst2last;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack *a, t_stack *b, int print)
{
	t_stack	*fst2last;
	t_stack	*lst2sec;

	fst2last = b->next;
	lst2sec = b->prev;
	b->next->next->prev = b;
	b->next = b->next->next;
	fst2last->next = b;
	fst2last->prev = b->prev;
	lst2sec->next = fst2last;
	b->prev = fst2last;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, b, 0);
	rb(a, b, 0);
	write(1, "rr\n", 3);
}


void	rra(t_stack *a, t_stack *b, int print)
{
	t_stack	*lst2fst;
	t_stack	*fst2sec;
	t_stack	*middle;

	lst2fst = a->prev;
	fst2sec = a->next;
	middle = a->next->next;
	lst2fst->next = fst2sec;
	lst2fst->prev = a;
	middle->next = a;
	middle->prev = fst2sec;
	fst2sec->next = middle;
	fst2sec->prev = lst2fst;
	a->next = lst2fst;
	a->prev = middle;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *a, t_stack *b, int print)
{
	t_stack	*lst2fst;
	t_stack	*fst2sec;
	t_stack	*middle;

	lst2fst = b->prev;
	fst2sec = b->next;
	middle = b->next->next;
	lst2fst->next = fst2sec;
	lst2fst->prev = b;
	middle->next = b;
	middle->prev = fst2sec;
	fst2sec->next = middle;
	fst2sec->prev = lst2fst;
	b->next = lst2fst;
	b->prev = middle;
	if (print)
		write(1, "rrb\n", 4);;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, b, 0);
	rrb(a, b, 0);
	write(1, "rrr\n", 4);
}

void	pa(t_stack *a, t_stack *b)
{
	t_stack	*bfst2afst;

	bfst2afst = b->next;
	b->next->prev = b;
	b->next = bfst2afst->next;
	a->next->prev = bfst2afst;
	bfst2afst->next = a->next;
	bfst2afst->prev = a;
	a->next = bfst2afst;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_stack	*afst2bfst;

	afst2bfst = a->next;
	a->next->prev = a;
	a->next = afst2bfst->next;
	b->next->prev = afst2bfst;
	afst2bfst->next = b->next;
	afst2bfst->prev = b;
	b->next = afst2bfst;
	write(1, "pb\n", 3);
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
	head->prev = now;
	return (head);
}


void	print_node(t_stack *node, int node_num, int argc)
{
	int node_index;
	char stack_type;

	puts("=========print start=========\n");
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
	puts("\n=========print fin=========");
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

void	swap3_case1(t_stack *a, t_stack *b)
{
	sa(a, b);
}

void	swap3_case2(t_stack *a, t_stack *b)
{
	sa(a, b);
	rra(a, b, 1);
}

void	swap3_case3(t_stack *a, t_stack *b)
{
	ra(a, b, 1);
}

void	swap3_case4(t_stack *a, t_stack *b)
{
	sa(a, b);
	ra(a, b, 1);
}

void	swap3_case5(t_stack *a, t_stack *b)
{
	rra(a, b, 1);
}

void	do_swap_3(t_stack *a, t_stack *b)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = a->next->num;
	num2 = a->next->next->num;
	num3 = a->prev->num;
	if (num1 > num2)
	{
		if (num2 < num3)
		{
			if (num1 < num3)
				swap3_case1(a, b);
			else if (num1 > num3)
				swap3_case3(a, b);
		}
		else if (num2 > num3)
			swap3_case2(a, b);
	}
	else if (num2 > num3)
	{
		if (num1 < num3)
			swap3_case4(a, b);
		else if (num1 > num3)
			swap3_case5(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack *a_stack;
	t_stack *b_stack;

	ps_error_check(argc, argv);
	b_stack = stack_setup();
	a_stack = make_list(argc, argv);
	do_swap_3(a_stack, b_stack);
	print_node(a_stack, 1, argc);
	// rra(a_stack, b_stack, 1);
	// print_node(a_stack, 1, argc);

	// system("leaks a.out");
}