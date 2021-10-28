#include "./../include/push_swap.h"

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