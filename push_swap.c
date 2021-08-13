#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				num;
}			t_stack;

t_stack	*add_list(int argc, char **argv)
{

}

void	print_node(t_stack *node, int node_num)
{
	int node_index;
	char stack_type;

	if (node_num)
		stack_type = 'a';
	else
		stack_type = 'b';
	node_index = 0;
	while (node->num)
	{
		printf("[%c]node[%d] = [%d]\n", stack_type, node_index, node->num);
		node_index++;
		node = node->next;
	}
}

void	ps_error_check(int argc, char **argv)
{
	int	num_tmp;
	int	arg_i;

	num_tmp = 0;
	arg_i = 0;
	while (arg_i < argc)
	[
		num_tmp = ft_atoi(argv[arg_i]);
	]


}

int	main(int argc, char **argv)
{
	t_stack *node;

	ps_error_check(argc, argv);
	node = add_list(argc, argv);
	print_stack(node, 1);
}