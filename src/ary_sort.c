/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ary_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:20:00 by hyudai            #+#    #+#             */
/*   Updated: 2021/12/13 16:30:31 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	node_to_ary(t_stack *a, int size, int *ary)
{
	int	node_index;

	node_index = 0;
	a = a->next;
	while (node_index < size && !a->fin)
	{
		ary[node_index] = a->num;
		node_index++;
		a = a->next;
	}
}

void	qsort_swap_number(int *ary, int i, int j)
{
	int	temp;

	temp = ary[i];
	ary[i] = ary[j];
	ary[j] = temp;
}

void	ft_qsort(int *ary, int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right;
	pivot = ary[(left + right) / 2];
	while (1)
	{
		while (ary[i] < pivot)
			i++;
		while (pivot < ary[j])
			j--;
		if (i >= j)
			break ;
		qsort_swap_number(ary, i, j);
		i++;
		j--;
	}
	if (left < i - 1)
		ft_qsort(ary, left, i - 1);
	if (j + 1 < right)
		ft_qsort(ary, j + 1, right);
}

int	get_median(t_stack *a, int size)
{
	int	*num_ary;
	int	median_num;

	num_ary = malloc(size * sizeof(int));
	node_to_ary(a, size, num_ary);
	ft_qsort(num_ary, 0, size - 1);
	median_num = num_ary[size / 2];
	free(num_ary);
	return (median_num);
}

void	sorted_check(int *ary, int argc)
{
	int	ary_index;

	ary_index = 0;
	while (ary_index + 1 < argc)
	{
		if (ary[ary_index] > ary[ary_index + 1])
			return ;
		if (ary[ary_index] == ary[ary_index + 1])
			error_exit();
		ary_index++;
	}
	exit (1);
}
