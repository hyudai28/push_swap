/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:20:51 by hyudai            #+#    #+#             */
/*   Updated: 2021/12/12 22:07:31 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	stack_next(t_stack *move)
{
	t_stack	*src;

	src = move;
	move = src->next;
	move->prev = src;
}

t_stack	*stack_setup(void)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	b->head = 1;
	b->next = NULL;
	b->prev = NULL;
	b->num = 0;
	return (b);
}

void	stack_setzero(t_stack *a)
{
	a->head = 1;
	a->num = 0;
	a->boundary = 0;
	a->fin = 0;
}

t_stack	*make_list(int argc, char **argv)
{
	t_stack	*head;
	t_stack	*now;
	t_stack	*new;
	int		struct_count;

	head = malloc(sizeof(t_stack));
	head->next = NULL;
	head->prev = NULL;
	stack_setzero(head);
	now = head;
	struct_count = 0;
	while (++struct_count < argc)
	{
		new = malloc(sizeof(t_stack));
		new->prev = now;
		new->next = head;
		new->num = ft_atoi(argv[struct_count]);
		new->head = 0;
		new->boundary = 0;
		new->fin = 0;
		now->next = new;
		now = now->next;
	}
	head->prev = now;
	return (head);
}

t_stack	*zsh_make_list(int argc, char **argv)
{
	t_stack	*head;
	t_stack	*now;
	t_stack	*new;
	int		struct_count;

	head = malloc(sizeof(t_stack));
	head->next = NULL;
	head->prev = NULL;
	stack_setzero(head);
	now = head;
	struct_count = -1;
	while (++struct_count < argc)
	{
		new = malloc(sizeof(t_stack));
		new->prev = now;
		new->next = head;
		new->num = ft_atoi(argv[struct_count]);
		new->head = 0;
		new->boundary = 0;
		new->fin = 0;
		now->next = new;
		now = now->next;
	}
	head->prev = now;
	return (head);
}
