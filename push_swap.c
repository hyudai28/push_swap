#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>

#define SORTSIZE 4

typedef struct s_order
{
	int		r_order;
	int		p_order;
	int		node_index;
	int		r_order_cpy;
	int		p_order_cpy;
}				t_order;


//atoi!!!!!!!!!!!!!!!

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	bool			head;
	int				num;
}			t_stack;


void	A_to_B(t_stack *a, t_stack *b, int num_size, int pivot);
void	B_to_A(t_stack *a, t_stack *b, int num_size, int pivot);

int	sa(t_stack *a)
{
	t_stack	*a_fst2sec;
	t_stack *a_sec2fst;

	a_fst2sec = a->next;
	a_sec2fst = a->next->next;
	a->next = a_sec2fst;
	a_fst2sec->prev = a_sec2fst;
	a_fst2sec->next = a_sec2fst->next;
	a_sec2fst->prev = a;
	a_sec2fst->next = a_fst2sec;
	write(1, "sa\n", 3);
	return (1);
}


int	sb(t_stack *b)
{
	t_stack	*b_fst2sec;
	t_stack *b_sec2fst;

	b_fst2sec = b->next;
	b_sec2fst = b->next->next;
	b->next = b_sec2fst;
	b_fst2sec->prev = b_sec2fst;
	b_fst2sec->next = b_sec2fst->next;
	b_sec2fst->prev = b;
	b_sec2fst->next = b_fst2sec;
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stack *a, t_stack *b)
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
	return (1);
}

int	ra(t_stack *a, int print)
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
	return (1);
}

int	rb(t_stack *b, int print)
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
	return (1);
}

int	rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
	return (1);
}


int	rra(t_stack *a, int print)
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
	return (1);
}

int	rrb(t_stack *b, int print)
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
		write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
	return (1);
}

int	pa(t_stack *a, t_stack *b)
{
	t_stack	*bfst2afst;

	if (!b->next)
	{
		write(1, "error\n", 6);
		return (0);
	}
	bfst2afst = b->next;
	b->next->next->prev = b;
	b->next = b->next->next;
	if (a->next)
		a->next->prev = bfst2afst;
	else
		b->prev = bfst2afst;
	if (a->next)
		bfst2afst->next = a->next;
	else
		bfst2afst->next = a;
	bfst2afst->prev = a;
	a->next = bfst2afst;
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack *a, t_stack *b)
{
	t_stack	*afst2bfst;

	if (!a->next)
	{
		write(1, "error\n", 6);
		return (0);
	}
	afst2bfst = a->next;
	a->next->next->prev = a;
	a->next = a->next->next;
	if (b->next)
		b->next->prev = afst2bfst;
	else
		b->prev = afst2bfst;
	if (b->next)
		afst2bfst->next = b->next;
	else
		afst2bfst->next = b;
	afst2bfst->prev = b;
	b->next = afst2bfst;
	write(1, "pb\n", 3);
	return (1);
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

int	swap3_case1(t_stack *a, t_stack *b)
{
	sa(a);
	return (1);
}

int	swap3_case2(t_stack *a, t_stack *b)
{
	sa(a);
	rra(a, 1);
	return (2);
}

int	swap3_case3(t_stack *a, t_stack *b)
{
	ra(a, 1);
	return (1);
}

int	swap3_case4(t_stack *a, t_stack *b)
{
	sa(a);
	ra(a, 1);
	return (2);
}

int	swap3_case5(t_stack *a, t_stack *b)
{
	rra(a, 1);
	return (1);
}

int	do_swap_3(t_stack *a, t_stack *b, int order)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = a->next->num;
	num2 = a->next->next->num;
	num3 = a->next->next->next->num;
	if (num1 > num2)
	{
		if (num2 < num3)
		{
			if (num1 < num3)
				order +=  swap3_case1(a, b);
			else if (num1 > num3)
				order += swap3_case3(a, b);
		}
		else if (num2 > num3)
			order += swap3_case2(a, b);
	}
	else if (num2 > num3)
	{
		if (num1 < num3)
			order += swap3_case4(a, b);
		else if (num1 > num3)
			order += swap3_case5(a, b);
	}
	return (order);
}

int	serch_min_num(t_stack *target)
{
	t_stack	*serch;
	int		min_num;
	int		num_index;
	int		num_index_ret;

	serch = target->next;
	min_num = serch->num;
	num_index = 1;
	num_index_ret = 1;
	while (!serch->head)
	{
		if (min_num > serch->num)
		{
			min_num = serch->num;
			num_index_ret = num_index;
		}
		serch = serch->next;
		num_index++;
	}
	return (num_index_ret);
}

int		target_ra_b(t_stack *a, t_stack *b, int target_index, int ra_or_rra)
{
	int	node_index;
	int order;

	node_index = 1;
	order = 0;
	while (node_index < target_index)
	{
		if (ra_or_rra)
			ra(a, 1);
		else
			rra(a, 1);
		order++;
		node_index++;
	}
	pb(a, b);
	return (order + 1);
}


int	num_pb(t_stack *a, t_stack *b, int target_index, int argc)
{
	int	node_index;
	int	order;
	t_stack *a_head;

	a_head = a;
	a = a->next;
	node_index = 1;
	order = 0;
	if (target_index <= argc / 2 + 1)
		order += target_ra_b(a_head, b, target_index, 1);
	else
		order += target_ra_b(a_head, b, target_index, 0);
	a = a->next;
	return (order);
}

int	min_num_pb(t_stack *a, t_stack *b, int argc)
{
	return (num_pb(a, b, serch_min_num(a), argc));
}

int	do_swap_5(t_stack *a, t_stack *b, int order, int argc)
{
	int		node_index;
	printf("===============%s=============\n", __func__);
	t_stack	*a_nextnext;
	
	node_index = 4;
	while (node_index < argc)
	{
		order += min_num_pb(a, b, argc);
		node_index++;
	}
	order += do_swap_3(a, b, 0);
	pa(a, b); 
	pa(a, b);
	printf("===============%s fin=============\n", __func__);
	return (order + 2);
}

int	do_swap_2(t_stack *a, t_stack *b, int order, int argc)
{
	if (argc == 2)
		return (0);
	if (a->next->num > a->next->next->num)
		sa(a);
	return (1);
}

void	node_to_ary(t_stack *a, int size, int *ary)
{
	int	node_index;

	node_index = 0;
	a = a->next;
	while (node_index < size)
	{
		ary[node_index] = a->num;
		node_index++;
		a = a->next;
	}
}

void	qsort_swap_number(int *ary, int i, int j)
{
	int	temp;

	temp = ary[i];
	ary[i] = ary[j];
	ary[j] = temp;
}


void	ft_qsort(int *ary, int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right;

	pivot = ary[(left + right) / 2];

	while (1)
	{
		while (ary[i] < pivot)
			i++;
		while (pivot < ary[j])
			j--;
		if (i >= j)
			break;
		qsort_swap_number(ary, i, j);
		i++;
		j--;
	}
	if (left < i - 1)
		ft_qsort(ary, left, i - 1);
	if (j + 1 < right)
		ft_qsort(ary, j + 1, right);
}



//syamashi
///*

int	half_set(t_stack *a, t_stack *b, int num_size)
{
	int	node_index;

	node_index = 0;
	while (node_index < num_size / 2)
	{
		pb(a, b);
		node_index++;
	}
	return (node_index);
}

int	count_stack_size(t_stack *stack)
{
	int	count_size;

	count_size = 0;
	stack = stack->next;
	while (!stack->head)
	{
		count_size++;
		stack = stack->next;
	}
	return (count_size);
}

int	b_quick_sort(t_stack *a, t_stack *b, int size)
{
	int	ary[size];
	int	half_num;
	int	size_i;
	int	order;

	order = 0;
	size_i = 0;
	node_to_ary(b, size, ary);
	ft_qsort(ary, 0, size - 1);
	half_num = ary[size / 2];
	while (size_i < size)
	{
		if (b->next->num > half_num)
			order += pa(a, b);
		else
			order += rb(b, 1);
		size_i++;
	}
	return (order);
}

int	allsort(t_stack *a, t_stack *b, int size)
{
	int	order;
	int	b2a_i;

	order = 0;
	order += pa(a, b);
	order += do_swap_3(b, a, order);
	b2a_i = 0;
	while (b2a_i < 3 && !b->next->head)
	{
		order += pa(a, b);
		if (a->next->num > a->next->next->num)
		{
			order += sa(a);
			order += ra(a, 1);
		}
		order += ra(a, 1);
	}
	return (order);
}

int	do_swap_over_6(t_stack *a, t_stack *b, int order, int num_size)
{
	int		size;
	int		sort_fin;

	order += half_set(a, b, num_size);
	size = count_stack_size(b);
	sort_fin = 0;
	while (sort_fin != num_size)
	{
		while ((size = count_stack_size(b)) > SORTSIZE)
			order += b_quick_sort(a, b, size);
		if (size)
			sort_fin += allsort(a, b, size);
		if (sort_fin < num_size)
			half_set(a, b, num_size - sort_fin);
		else if (sort_fin > num_size)
			write(1, "miss your algorithm\n", 20);
	}
	return (0);
}

//*/

void	show_data(int *ary, int size)
{
	int	i = 0;

	while (i < size)
	{
		printf("ary[%d] = [%d]\n", i, ary[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack *a_stack;
	t_stack *b_stack;
	int		order;

printf("argc = [%d]\n", argc);
	ps_error_check(argc, argv);
	b_stack = stack_setup();
	a_stack = make_list(argc, argv);

	int ary_index = 0;
	int ary[argc - 1];
	node_to_ary(a_stack, argc - 1, ary);
	show_data(ary, argc - 1);
	ft_qsort(ary, 0, argc - 2);
	printf("==========\n");
	show_data(ary, argc - 1);
	exit(1);




	order = 0;
	if (argc <= 3)
		order = do_swap_2(a_stack, b_stack, order, argc);
	else if (argc == 4)
		order = do_swap_3(a_stack, b_stack, order);
	else if (argc <= 6)
		order = do_swap_5(a_stack, b_stack, order, argc);
	else
	{
		//A_to_B(a_stack, b_stack, argc - 1, 0);
		order = do_swap_over_6(a_stack, b_stack, order, argc - 1);
	}
	print_node(a_stack, 1, argc);
	print_node(b_stack, 0, argc);
	printf("order = [%d]\n", order);
}