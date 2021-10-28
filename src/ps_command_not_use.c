/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_command_not_use.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:21:25 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/28 19:27:25 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	ss(t_stack *a, t_stack *b)
{
	t_stack	*a_fst2sec;
	t_stack	*a_sec2fst;
	t_stack	*b_fst2sec;
	t_stack	*b_sec2fst;

	a_fst2sec = a;
	a_fst2sec = a_fst2sec->next;
	a_sec2fst = a_fst2sec->next;
	a->next = a_sec2fst;
	a_fst2sec->prev = a_sec2fst;
	a_fst2sec->next = a_sec2fst->next;
	a_sec2fst->prev = a;
	a_sec2fst->next = a_fst2sec;
	b_fst2sec = b;
	b_fst2sec = b_fst2sec->next;
	b_sec2fst = b_fst2sec->next;
	b->next = b_sec2fst;
	b_fst2sec->prev = b_sec2fst;
	b_fst2sec->next = b_sec2fst->next;
	b_sec2fst->prev = b;
	b_sec2fst->next = b_fst2sec;
	write(1, "ss\n", 3);
	return (1);
}

int	rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
	return (1);
}

int	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
	return (1);
}
