#include "./../include/push_swap.h"

void	error_exit(void)
{
	printf("Error\n");
	exit(1);
}

void	arg_error(long num, char *argv)
{
	if (num == 0)
	{
		if (argv[0] != '0')
			error_exit();
	}
	if (num < -2147483648 || num > 2147483647)
			error_exit();
}

void ps_error_check(int argc, char **argv)
{
	long	num_tmp;
	int		ary[argc - 1];
	int		arg_i;

	if (argc < 2)
		exit(1);
	num_tmp = 0;
	arg_i = 1;
	while (arg_i < argc)
	{
		num_tmp = ft_atoi(argv[arg_i]);
		arg_error(num_tmp, argv[arg_i]);
		ary[arg_i - 1] = num_tmp;
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