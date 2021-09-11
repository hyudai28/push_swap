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

int	sa(t_stack *a, t_stack *b)
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


int	sb(t_stack *a, t_stack *b)
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

int	ra(t_stack *a, t_stack *b, int print)
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

int	rb(t_stack *a, t_stack *b, int print)
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
	ra(a, b, 0);
	rb(a, b, 0);
	write(1, "rr\n", 3);
	return (1);
}


int	rra(t_stack *a, t_stack *b, int print)
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

int	rrb(t_stack *a, t_stack *b, int print)
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
	rra(a, b, 0);
	rrb(a, b, 0);
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
	sa(a, b);
	return (1);
}

int	swap3_case2(t_stack *a, t_stack *b)
{
	sa(a, b);
	rra(a, b, 1);
	return (2);
}

int	swap3_case3(t_stack *a, t_stack *b)
{
	ra(a, b, 1);
	return (1);
}

int	swap3_case4(t_stack *a, t_stack *b)
{
	sa(a, b);
	ra(a, b, 1);
	return (2);
}

int	swap3_case5(t_stack *a, t_stack *b)
{
	rra(a, b, 1);
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
			ra(a, b, 1);
		else
			rra(a, b, 1);
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
	//print_node(a, 1, argc);
	//print_node(b, 0, argc);
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
		sa(a, b);
	return (1);
}

int	*node_to_ary(t_stack *a, int size)
{
	int	ary[size];
	int	node_index;

	node_index = 0;
	a = a->next;
	while (!a->head)
	{
		ary[node_index++] = a->num;
		a = a->next;
	}
	return (ary);
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
/*

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
		//b_settle_top(a, b);
		while ((size = count_stack_size(b)) > SORTSIZE)
			order += b_quick_sort(a, b, size);
		if (size)
			order += allsort(a, b, size);
		while ((size = serch_a_size(a)) && size <= SORTSIZE)
			order += allsort(a, b, size);
		if (size)
			order += a_quick_sort(a, b, size);
	}
}

*/



/* korean


int	serch_median(t_stack *stack, int num_size)
{
	int	pivot;
	int	stack_index;
	int	stack_ary[num_size + 1];

	stack_index = 0;
	stack = stack->next;
	while (stack_index < num_size)
		stack_ary[stack_index++] = stack->num;
	ft_qsort(stack_ary, 0, num_size - 1);
	pivot = stack_ary[num_size / 2];
	return (pivot);
}


void	A_to_B(t_stack *a, t_stack *b, int num_size, int pivot)
{
	t_order	order;
	t_stack	*a_node;

	order = (t_order){};
	a_node = a->next;
	pivot = serch_median(a, num_size);
	while (order.node_index < num_size)
	{
		if (a_node->num > pivot)
			order.r_order += ra(a, b, 1);
		else
			order.p_order += pb(a, b);
		a_node = a_node->next;
		order.node_index++;
	}
	while (order.r_order > 0)
	{
		rra(a, b, 1);
		order.r_order--;
	}
	order.r_order_cpy = order.r_order;
	order.p_order_cpy = order.p_order;
	A_to_B(a, b, order.r_order_cpy, pivot);
	B_to_A(a, b, order.p_order_cpy, pivot);
}

void	B_to_A(t_stack *a, t_stack *b, int num_size, int pivot)
{
	t_order	order;
	t_stack	*b_node;

	order = (t_order){};
	b_node = b->next;
	while (order.node_index < num_size)
	{
		if (b_node->num > pivot)
			order.r_order += rb(a, b, 1);
		else
			order.p_order += pa(a, b);
		b_node = b_node->next;
		order.node_index++;
	}
	order.r_order_cpy = order.r_order;
	order.p_order_cpy = order.p_order;
	while (order.r_order > 0)
	{
		rra(a, b, 1);
		order.r_order--;
	}
	order.r_order_cpy = order.r_order;
	order.p_order_cpy = order.p_order;
	A_to_B(a, b, order.r_order_cpy, pivot);
	B_to_A(a, b, order.p_order_cpy, pivot);
}


*/


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
	int *ary = node_to_ary(a_stack, argc - 1);
	while (ary[ary_index])
		printf("ary[%d] = [%d]\n", ary_index, ary[ary_index++]);
	ft_qsort(ary, 0, argc - 1);
	while (ary[ary_index])
		printf("ary[%d] = [%d]\n", ary_index, ary[ary_index++]);
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