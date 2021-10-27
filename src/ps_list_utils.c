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


void	print_node(t_stack *node, int node_num)
{
	int node_index;
	char stack_type;

	puts("=========print start=========\n");
	if (node_num == LIST_A)
		stack_type = 'a';
	else
		stack_type = 'b';
	node_index = 1;
	if (!node->next)
		return ;
	node = node->next;
	while (!node->head)
	{
		printf("[%c]node[%3d] = [%8d]___fin =[%d]___boundary = [%d]\n", stack_type, node_index, node->num, node->fin, node->boundary);
		node_index++;
		node = node->next;
	}
	puts("\n=========print fin=========");
}

void	restore_node_ptr(t_stack *node)
{
	//while (!node->head)
	//{
	//	//printf("num =[%d]\n", node->num);
	//	node = node->next;
	//}
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
	restore_node_ptr(node);
	return (node_index);
}
