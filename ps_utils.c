#include "push_swap.h"

void	ps_error_check(int argc, char **argv)
{
	int	num_tmp;
	int	arg_i;

	if (argc < 2)
	{
		exit(1);
	}
	num_tmp = 0;
	arg_i = 0;
	while (arg_i < argc)
	{
		num_tmp = atoi(argv[arg_i]);
		arg_i++;
	}
}

int	serch_min_num(t_stack *target)
{
	t_stack	*serch;
	int		min_num;
	int		num_index;
	int		num_index_ret;

	serch = target->next;
	min_num = serch->num;
	num_index = 1;
	num_index_ret = 1;
	while (!serch->head)
	{
		if (min_num > serch->num)
		{
			min_num = serch->num;
			num_index_ret = num_index;
		}
		serch = serch->next;
		num_index++;
	}
	return (num_index_ret);
}