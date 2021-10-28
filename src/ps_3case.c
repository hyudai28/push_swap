/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_3case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:20:14 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/28 19:20:15 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	swap3_case1(t_stack *target, int list_flag)
{
	if (list_flag == LIST_A)
		sa(target);
	else
		sb(target);
	return (1);
}

int	swap3_case2(t_stack *target, int list_flag)
{
	if (list_flag == LIST_A)
	{
		sa(target);
		rra(target, 1);
	}
	else
	{
		sb(target);
		rrb(target, 1);
	}
	return (2);
}

int	swap3_case3(t_stack *target, int list_flag)
{
	if (list_flag == LIST_A)
		ra(target, 1);
	else
		rb(target, 1);
	return (1);
}

int	swap3_case4(t_stack *target, int list_flag)
{
	if (list_flag == LIST_A)
	{
		sa(target);
		ra(target, 1);
	}
	else
	{
		sb(target);
		rb(target, 1);
	}
	return (2);
}

int	swap3_case5(t_stack *target, int list_flag)
{
	if (list_flag == LIST_A)
		rra(target, 1);
	else
		rrb(target, 1);
	return (1);
}
