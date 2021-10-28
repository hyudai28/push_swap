#include "./../include/push_swap.h"

int	sa(t_stack *a)
{
	int	tmp;

	tmp = a->next->num;
	a->next->num = a->next->next->num;
	a->next->next->num = tmp;
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack *b)
{
	int	tmp;

	tmp = b->next->num;
	b->next->num = b->next->next->num;
	b->next->next->num = tmp;
	write(1, "sb\n", 3);
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
