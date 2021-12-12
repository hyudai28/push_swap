/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:21:45 by hyudai            #+#    #+#             */
/*   Updated: 2021/12/12 21:59:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
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

void	ps_error_check(int argc, char **argv)
{
	long	num_tmp;
	int		arg_i;

	if (argc < 2)
		exit(1);
	num_tmp = 0;
	arg_i = 1;
	while (arg_i < argc)
	{
		num_tmp = ft_atoi(argv[arg_i]);
		arg_error(num_tmp, argv[arg_i]);
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

void	ary_check(t_stack *a, int num_size)
{
	int	i;
	int	*ary;

	ary = malloc(num_size * sizeof(int));
	node_to_ary(a, num_size, ary);
	sorted_check(ary, num_size);
	ft_qsort(ary, 0, num_size - 1);
	i = 0;
	while (i + 1 < num_size)
	{
		if (ary[i] == ary[i + 1])
			error_exit();
		i++;
	}
	free(ary);
}
