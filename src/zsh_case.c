/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zsh_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai </var/mail/hyudai>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:08:58 by hyudai            #+#    #+#             */
/*   Updated: 2021/12/12 22:09:00 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	zsh_number_is_int(char *argv, int split_count)
{
	long	num_tmp;

	num_tmp = ft_atoi(argv);
	arg_error(num_tmp, argv);
	if (split_count > 1)
		return (0);
	exit(1);
}

void	zsh_case(char *argv)
{
	int		split_count;
	char	**new_argv;
	t_stack	*a;
	t_stack	*b;

	split_count = ft_split_count(argv, ' ');
	zsh_number_is_int(argv, split_count);
	new_argv = ft_split(argv, ' ');
	ps_error_check(split_count, new_argv);
	a = zsh_make_list(split_count, new_argv);
	b = stack_setup();
	ary_check(a, split_count);
	if (split_count <= 2)
		do_swap_2(a, LIST_A);
	else if (split_count == 3)
		swap_3(a, LIST_A);
	else if (split_count == 4)
		swap_4(a, b);
	else if (split_count <= 5)
		do_swap_over_5(a, b);
	else
		do_swap_over_6(a, b, split_count);
}

void	swap_4(t_stack *a, t_stack *b)
{
	int	median;
	int	i;
	int	pb_index;

	median = get_median(a, 4);
	i = 0;
	pb_index = 0;
	while (i++ < 4)
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
}
