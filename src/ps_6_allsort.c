#include "./../include/push_swap.h"

void	allsort_swap2_3(t_stack *b, int b2a_i)
{
	if (b2a_i == 2)
		do_swap_2(b, LIST_B);
	else
		swap_3(b, LIST_B);
}

int	allsort_4case(t_stack *a, t_stack *b)
{
	if (get_node_count(b) == 4)
	{
		pa(a, b);
		return (1);
	}
	return (0);
}

int	allsort(t_stack *a, t_stack *b)
{
	int		b2a_i;
	bool	flag;

	b2a_i = get_node_count(b);
	flag = allsort_4case(a, b);
	allsort_swap2_3(b, b2a_i);
	while (b2a_i > 0 && !b->next->head)
	{
		if (flag)
			if (b->next->num > a->next->num)
			{
				ra(a, 1);
				a->prev->fin = 1;
				flag = 0;
				b2a_i--;
			}
		pa(a, b);
		ra(a, 1);
		a->prev->fin = 1;
		b2a_i--;
	}
	if (flag)
		ra(a, 1);
	return (0);
}