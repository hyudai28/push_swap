/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:20:42 by hyudai            #+#    #+#             */
/*   Updated: 2021/12/12 22:02:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	rra(t_stack *a, int print)
{
	t_stack	*target;
	t_stack	*before_target;
	t_stack	*next_head;

	target = a->prev;
	next_head = a->next;
	before_target = target->prev;
	before_target->next = a;
	target->next = next_head;
	target->prev = a;
	a->next = target;
	a->prev = before_target;
	next_head->prev = target;
	if (print)
		write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stack *b, int print)
{
	t_stack	*target;
	t_stack	*before_target;
	t_stack	*next_head;

	target = b->prev;
	next_head = b->next;
	before_target = b->prev->prev;
	b->next = target;
	b->prev = before_target;
	target->prev = b;
	target->next = next_head;
	next_head->prev = target;
	before_target->next = b;
	if (print)
		write(1, "rrb\n", 4);
	return (1);
}

int	pa(t_stack *a, t_stack *b)
{
	t_stack	*bfst2afst;

	if (!b->next)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	bfst2afst = b->next;
	b->next->next->prev = b;
	b->next = b->next->next;
	if (a->next)
		a->next->prev = bfst2afst;
	else
		b->prev = bfst2afst;
	if (a->next)
		bfst2afst->next = a->next;
	else
		bfst2afst->next = a;
	bfst2afst->prev = a;
	a->next = bfst2afst;
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack *a, t_stack *b)
{
	t_stack	*afst2bfst;

	if (!a->next)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	afst2bfst = a->next;
	a->next->next->prev = a;
	a->next = a->next->next;
	if (b->next)
		b->next->prev = afst2bfst;
	else
		b->prev = afst2bfst;
	if (b->next)
		afst2bfst->next = b->next;
	else
		afst2bfst->next = b;
	afst2bfst->prev = b;
	b->next = afst2bfst;
	write(1, "pb\n", 3);
	return (1);
}
