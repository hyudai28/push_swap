#include "./../include/push_swap.h"


void	stack_next(t_stack *move)
{
	t_stack *src;

	src = move;
	move = src->next;
	move->prev = src;
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
	head->boundary = 0;
	head->fin = 0;
	now = head;
	struct_count = 0;
	while (++struct_count < argc)
	{
		new = malloc(sizeof(t_stack));
		new->prev = now;
		new->next = head;
		new->num = atoi(argv[struct_count]);
		new->head = 0;
		new->boundary = 0;
		new->fin = 0;
		now->next = new;
		now = now->next;
	}
	head->prev = now;
	return (head);
}
