#include "push_swap.h"

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
	t_stack	*target;
	t_stack	*before_target;
	t_stack	*next_head;

	target = a->prev;
	next_head = a->next;
	before_target = target->prev;
	before_target->next = a;
	target->next = next_head;
	target->prev = a;
	a->next = target;
	a->prev = before_target;
	next_head->prev = target;
	if (print)
		write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stack *b, int print)
{
	t_stack	*target;
	t_stack	*before_target;
	t_stack	*next_head;

	target = b->prev;
	next_head = b->next;
	before_target = b->prev->prev;

	b->next = target;
	b->prev = before_target;
	target->prev = b;
	target->next = next_head;
	next_head->prev = target;
	before_target->next = b;
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

