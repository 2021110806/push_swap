/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:16:25 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/29 08:34:59 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_linked_list		*stack_a;
	t_linked_list		*stack_b;
	t_moving_counter	*min_moving;
	t_node				*node;

	stack_a = make_new_list();
	stack_b = make_new_list();
	min_moving = malloc (sizeof (t_moving_counter));
	if (!is_valid_input(argv, argc, stack_a))
		return (1);
	if (is_sorted(stack_a))
		return (0);
	if (argc > 1 && argc <= 6)
		return (sort_when_input_is_few(stack_a, stack_b));
	make_stack_to_idx(stack_a);
	partition(stack_a, stack_b);
	node = stack_b -> head -> prev;
	while (node != stack_b -> head)
	{
		find_minimum_greedy(stack_a, stack_b, min_moving);
		rotate_stack(stack_a, stack_b, min_moving);
		pa(stack_a, stack_b);
		node = stack_b -> head -> prev;
	}
	return (move_min_value_to_top(stack_a));
}
