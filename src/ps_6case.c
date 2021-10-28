#include "./../include/push_swap.h"

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
		node_index++;
	}
}

int	half_a_to_b(t_stack *a, t_stack *b, int num_size, int sort_fin)
{
	int	median_num;
	int	ra_index;
	int	unsorted;

	unsorted = unsorted_num(a);
	if (!unsorted)
		return (0);
	else if (unsorted <= SORTSIZE)
		return (all_to_b(a, b));
	ra_index = 0;
	median_num = get_median(a, node_count(a));
	while (!a->next->fin && !a->next->boundary\
	&& node_count(b) < num_size / 2)
	{
		if (a->next->num < median_num || sort_fin)
			pb(a, b);
		else
			ra_index += ra(a, 1);
		if (a->next->head == 1)
			return (0);
	}
	if (a->next->boundary)
		pb(a, b);
	opt_is_notfirst(a, ra_index);
	return (1);
}