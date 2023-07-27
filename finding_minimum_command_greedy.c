/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_minimum_command_greedy.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:57:27 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/27 23:37:49 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_command_in_stack_a(int target, t_linked_list *stack_a, \
							t_moving_counter *moving_counter)
{
	t_node				*node;

	node = stack_a -> head -> prev;
	moving_counter -> ra = 0;
	moving_counter -> rra = 0;
	if (stack_a -> size == 1 || stack_a -> size == 0)
	{
		moving_counter -> rb = 0;
		moving_counter -> rrb = 0;
		return (1);
	}
	if (target <= min(stack_a))
		count_command_when_target_is_min(target, moving_counter, stack_a);
	else if (target >= max(stack_a))
		count_command_when_target_is_max(target, moving_counter, stack_a);
	else if (stack_a -> head -> prev != stack_a -> head && \
	stack_a -> head -> next != stack_a -> head && ((stack_a \
	-> head -> prev -> item > target && stack_a -> head -> \
	next -> item < target) || (stack_a -> head -> prev -> item \
	< target && stack_a -> head -> next -> item > target)))
		count_command_when_target_is_top(target, moving_counter, stack_a);
	else
		count_command_when_general_case(stack_a, target, moving_counter);
	return (1);
}

int count_command_in_stack_b(int idx, t_linked_list *stack_b, \
t_moving_counter *moving_counter)
{
	if (idx == stack_b -> size - 1)
	{
		moving_counter -> rrb = 1;
		moving_counter -> rb = 0;
		return (1);
	}
	if (idx <= stack_b -> size / 2)
	{
		moving_counter -> rb = idx;
		moving_counter -> rrb = 0;
	}
	else
	{
		moving_counter -> rrb = stack_b -> size - (idx);
		moving_counter -> rb = 0;
	}
	return (1);
}

t_moving_counter	*find_minimum_greedy(t_linked_list *stack_a, \
t_linked_list *stack_b)
{
	t_node 			*node;
	t_moving_counter *moving_counter;
	t_moving_counter *min_moving;
	int				stack_idx;

	stack_idx = 0;
	node = stack_b -> head -> next;
	moving_counter = malloc (sizeof(t_moving_counter));
	min_moving = malloc (sizeof(t_moving_counter));
	count_command_in_stack_a(node -> item, stack_a, moving_counter);
	count_command_in_stack_b(stack_idx, stack_b, moving_counter);
	min_moving -> ra = moving_counter -> ra;
	min_moving -> rra = moving_counter -> rra;
	min_moving -> rb = moving_counter -> rb;
	min_moving -> rrb = moving_counter -> rrb;
	stack_idx++;
	node = node -> next;
	while (node != stack_b -> head)
	{
		count_command_in_stack_a(node -> item, stack_a, moving_counter);
		count_command_in_stack_b(stack_idx, stack_b, moving_counter);
		if (min_moving -> rra + min_moving -> ra + min_moving -> rb + min_moving -> rrb \
			> moving_counter -> rra + moving_counter -> ra + moving_counter -> rb + moving_counter -> rrb)
		{
			min_moving -> ra = moving_counter -> ra;
			min_moving -> rra = moving_counter -> rra;
			min_moving -> rb = moving_counter -> rb;
			min_moving -> rrb = moving_counter -> rrb;
		}
		node = node -> next;
		stack_idx++;
	}
	return (min_moving);
}