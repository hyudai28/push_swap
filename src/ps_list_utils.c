#include "./../include/push_swap.h"

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

int		get_node_count(t_stack *node)
{
	int	node_index;

	node_index = 0;
	if (!node->next)
		return (0);
	node = node->next;
	while (!node->head)
	{
		node_index++;
		node = node->next;
	}
	return (node_index);
}

int	node_count(t_stack *node)
{
	int	ret;

	if (!node->next)
		return (0);
	node = node->next;
	ret = 0;
	while (!node->head && !node->fin)
	{
		ret++;
		node = node->next;
	}
	return (ret);
}

int	b_quick_sort(t_stack *a, t_stack *b)
{
	int	back_i;

	back_i = 0;
	while (get_node_count(b) > SORTSIZE)
	{
		ps_b_qsort(a, b);
		back_i++;
	}
	return (0);
}