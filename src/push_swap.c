#include "./../include/push_swap.h"

void	A_to_B(t_stack *a, t_stack *b, int num_size, int pivot);
void	B_to_A(t_stack *a, t_stack *b, int num_size, int pivot);
int	get_median(t_stack *a, int size);

int	node_count(t_stack *node)
{
	int	ret;

	if (!node->next)
	{
		printf("error !! node繋がってなくね？\n");
		exit(1);
	}
	node = node->next;
	ret = 0;
	while (!node->head && !node->fin)
	{
		ret++;
		node = node->next;
	}
	restore_node_ptr(node);
	return (ret);
}

//flagが1の時は中央値よりも上を飛ばす、0の時は以下を飛ばす
void	ps_a_qsort(t_stack *a, t_stack *b)
{
	int	median;
	int	node_size;
	int	node_index;

	node_size = get_node_count(a);
	median = get_median(a, node_size);
	while (node_index < node_size && !a->fin\
		&& !a->boundary)
	{
		if (a->num <= median)
			pb(a, b);
		a = a->next;
		node_index++;
	}
	restore_node_ptr(a);
}

void	ps_b_qsort(t_stack *a, t_stack *b)
{
	int	median;
	int	node_size;
	int	node_index;
	int	boundary_flag;

	boundary_flag = 1;
	node_index = 0;
	node_size = get_node_count(b);
	median = get_median(b, node_size);
	printf("median=[%d]\n", median);
	while (node_index < node_size)
	{
		if (b->next->num > median)
		{
			if (boundary_flag)
			{
				b->next->boundary = 1;
				boundary_flag = 0;
			}
			pa(a, b);
		}
		else
			rb(b, 1);
		b = b->next;
		node_index++;
	}
	restore_node_ptr(b);
}

int	do_swap_2(t_stack *node, int list_flag)
{
	if (list_flag == LIST_A)
	{
		if (node->next->num > node->next->next->num)
			sa(node);
	}
	else
	{
		if (node->next->num > node->next->next->num)
			sb(node);
	}
	return (1);
}

void	node_to_ary(t_stack *a, int size, int *ary)
{
	int	node_index;

	node_index = 0;
	a = a->next;
	while (node_index < size && !a->fin)
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

int	unsorted_num(t_stack *node)
{
	int	unsorted;

	unsorted = 0;
	node = node->next;
	while (!node->fin && !node->head)
	{
		node = node->next;
		unsorted++;
	}
	restore_node_ptr(node);
	return (unsorted);
}

int	all_to_b(t_stack *a, t_stack *b)
{
	while (!a->next->fin)
		pb(a, b);
	return (1);
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

int	b_quick_sort(t_stack *a, t_stack *b)
{
	int	back_i;

	back_i = 0;
	while (get_node_count(b) > SORTSIZE)
	{
		print_node(a, 1);
		print_node(b, 0);
		ps_b_qsort(a, b);
		back_i++;
	}
	return (0);
}

int	allsort(t_stack *a, t_stack *b)
{
	int		b2a_i;
	int		b_index;
	bool	flag;

	b2a_i = get_node_count(b);
	b_index = get_node_count(b);
	if (get_node_count(b) == 4)
	{
		pa(a, b);
		flag = 1;
	}
	if (b2a_i == 2)
		do_swap_2(b, LIST_B);
	else
		swap_3(b, LIST_B);
	while (b2a_i > 0)
	{
		if (flag)
		{
			if (b->next->num > a->next->num)
			{
				ra(a, 1);
				a->prev->fin = 1;
				flag = 0;
				b2a_i--;
				b_index--;
			}
		}
		pa(a, b);
		ra(a, 1);
		a->prev->fin = 1;
		b2a_i--;
	}
	return (0);
}

int	get_median(t_stack *a, int size)
{
	int	num_ary[size];
	int	median_num;

	node_to_ary(a, size, num_ary);
	ft_qsort(num_ary, 0, size - 1);
	median_num = num_ary[size / 2];
	return (median_num);
}

int	half_a_to_b(t_stack *a, t_stack *b, int num_size, int sort_fin)
{
	int	list_index;
	int	median_num;
	int	ra_index;
	int	unsorted;

	list_index = 0;
	ra_index = 0;
	unsorted = unsorted_num(a);
	if (!unsorted)
		return (0);
	else if (unsorted <= SORTSIZE)
		return (all_to_b(a, b));
	median_num = get_median(a, node_count(a));
	while (!a->next->fin && list_index <= num_size)
	{
		if (a->next->boundary == 1 || a->next->fin == 1)
			break;
		if (a->next->num < median_num || sort_fin)
			pb(a, b);
		else
		{
			ra(a, 1);
			ra_index++;
		}
		list_index++;
		if (a->next->head == 1)
			return (0);
	}
	if (a->next->boundary)
		pb(a, b);
	while (ra_index-- > 0)
		rra(a, 1);
	return (1);
}

int	do_swap_over_6(t_stack *a, t_stack *b, int num_size)
{
	int		sort_fin;

	sort_fin = 0;
	while (half_a_to_b(a, b, num_size, sort_fin))
	{
		print_node(a, 1);
		print_node(b, 0);
		puts("b_quick_sort");
		b_quick_sort(a, b);
		print_node(a, 1);
		print_node(b, 0);
		puts("all_sort");
		sort_fin = allsort(a, b);
		//print_node(a, 1);
		//print_node(b, 0);
	}
	return (0);
}

void	show_data(int *ary, int size)
{
	int	i = 0;

	while (i < size)
	{
		printf("ary[%d] = [%d]\n", i, ary[i]);
		i++;
	}
}

void	print_check(t_stack *a, t_stack *b)
{
	print_node(b, 1);
	print_node(a, 1);
	print_node(b, 0);
	exit (1);
}

void	sorted_check(int *ary, int argc)
{
	int	ary_index;

	ary_index = 0;
	while (ary_index + 1 < argc)
	{
		if (ary[ary_index] > ary[ary_index + 1])
			return ;
		ary_index++;
	}
	exit (1);
}

int	do_swap_over_5(t_stack *a, t_stack *b)
{
	int	median;
	int	i;
	int	pb_index;
	
	median = get_median(a, 5);
	i = 0;
	pb_index = 0;
	while (i++ < 5)
	{
		if (a->next->num > median)
		{
			pb(a, b);
			pb_index++;
		}
		else
			ra(a, 1);
		if (pb_index == 3)
			break ;
	}
	swap_3(a, LIST_A);
	do_swap_2(b, LIST_B);
	pa(a, b);
	ra(a, 1);
	pa(a, b);
	ra(a, 1);
	return (0);
}

void	ary_check(t_stack *a, int num_size)
{
	int	i;
	int ary[num_size];

	node_to_ary(a, num_size, ary);
	sorted_check(ary, num_size);
	ft_qsort(ary, 0, num_size - 1);
	i = 0;
	while (i + 1 < num_size)
	{
		if (ary[i] == ary[i + 1])
			error_exit();
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack *a_stack;
	t_stack *b_stack;

	ps_error_check(argc, argv);
	b_stack = stack_setup();
	a_stack = make_list(argc, argv);
	ary_check(a_stack, argc - 1);
	if (argc <= 3)
		do_swap_2(a_stack, LIST_A);
	else if (argc == 4)
		swap_3(a_stack, LIST_A);
	else if (argc <= 6)
		do_swap_over_5(a_stack, b_stack);
	else
		do_swap_over_6(a_stack, b_stack, argc - 1);
	// print_node(a_stack, 1);
	// print_node(b_stack, 0);
	// system("leaks a.out");
}