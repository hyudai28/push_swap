/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_6case_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:20:29 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/28 19:20:30 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	opt_is_nextfin(t_stack *a, int not_first)
{
	if (a->next->fin || not_first)
		return (1);
	return (0);
}

void	opt_is_notfirst(t_stack *a, int ra_index)
{
	if (a->next->fin)
	{
		while (ra_index-- > 0)
			rra(a, 1);
	}
}

int	all_to_b(t_stack *a, t_stack *b)
{
	while (!a->next->fin)
		pb(a, b);
	return (1);
}

int	unsorted_num(t_stack *node)
{
	int	unsorted;

	unsorted = 0;
	if (!node->next)
		return (0);
	node = node->next;
	while (!node->fin && !node->head)
	{
		node = node->next;
		unsorted++;
	}
	return (unsorted);
}
