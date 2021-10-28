/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_6_allsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:21:14 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/28 19:39:54 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	allsort_swap2_3(t_stack *b, int b2a_i)
{
	if (b2a_i == 2)
		do_swap_2(b, LIST_B);
	else
		swap_3(b, LIST_B);
}

int	allsort_4case(t_stack *a, t_stack *b)
{
	if (get_node_count(b) == 4)
	{
		pa(a, b);
		return (1);
	}
	return (0);
}

void	fcknorm(t_stack *a, t_stack *b)
{
	pa(a, b);
	ra(a, 1);
}

int	allsort(t_stack *a, t_stack *b)
{
	int		b2a_i;
	bool	flag;

	b2a_i = get_node_count(b);
	flag = allsort_4case(a, b);
	allsort_swap2_3(b, b2a_i);
	while (b2a_i > 0 && !b->next->head)
	{
		if (flag)
		{
			if (b->next->num > a->next->num)
			{
				ra(a, 1);
				a->prev->fin = 1;
				flag = 0;
				b2a_i--;
			}
		}
		fcknorm(a, b);
		a->prev->fin = 1;
		b2a_i--;
	}
	if (flag)
		ra(a, 1);
	return (0);
}
