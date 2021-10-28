/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:22:43 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/28 19:26:50 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	do_swap_2(t_stack *node, int list_flag)
{
	if (list_flag == LIST_A)
	{
		if (node->next->num > node->next->next->num)
			sa(node);
	}
	else
	{
		if (node->next->num > node->next->next->num)
			sb(node);
	}
	return (1);
}

int	swap_3(t_stack *target, int list_flag)
{
	int	num2;
	int	num3;

	num2 = target->next->next->num;
	num3 = target->next->next->next->num;
	if (target->next->num >= num2)
	{
		if (num2 <= num3)
		{
			if (target->next->num < num3)
				swap3_case1(target, list_flag);
			else if (target->next->num >= num3)
				swap3_case3(target, list_flag);
		}
		else if (num2 > num3)
			swap3_case2(target, list_flag);
	}
	else if (num2 >= num3)
	{
		if (target->next->num < num3)
			swap3_case4(target, list_flag);
		else if (target->next->num > num3)
			swap3_case5(target, list_flag);
	}
	return (0);
}

void	do_swap_over_5(t_stack *a, t_stack *b)
{
	int	median;
	int	i;
	int	pb_index;

	median = get_median(a, 5);
	i = 0;
	pb_index = 0;
	while (i++ < 5)
	{
		if (a->next->num > median)
		{
			pb(a, b);
			pb_index++;
		}
		else
			ra(a, 1);
		if (pb_index == 3)
			break ;
	}
	swap_3(a, LIST_A);
	do_swap_2(b, LIST_B);
	pa(a, b);
	ra(a, 1);
	pa(a, b);
	ra(a, 1);
}

int	do_swap_over_6(t_stack *a, t_stack *b, int num_size)
{
	int		sort_fin;

	sort_fin = 0;
	while (half_a_to_b(a, b, num_size, sort_fin))
	{
		b_quick_sort(a, b);
		sort_fin = allsort(a, b);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	ps_error_check(argc, argv);
	b_stack = stack_setup();
	a_stack = make_list(argc, argv);
	ary_check(a_stack, argc - 1);
	if (argc <= 3)
		do_swap_2(a_stack, LIST_A);
	else if (argc == 4)
		swap_3(a_stack, LIST_A);
	else if (argc <= 6)
		do_swap_over_5(a_stack, b_stack);
	else
		do_swap_over_6(a_stack, b_stack, argc - 1);
}
