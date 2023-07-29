/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_minimum_command_greedy.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:57:27 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/30 03:41:24 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sum_moving_counter(t_moving_counter *moving_counter)
{
	int	return_value;

	return_value = 0;
	return_value += moving_counter -> ra;
	return_value += moving_counter -> rra;
	return_value += moving_counter -> rb;
	return_value += moving_counter -> rrb;
	return (return_value);
}

void	count_command_in_stack_a(int target, t_linked_list *stack_a, \
							t_moving_counter *moving_counter)
{
	moving_counter -> ra = 0;
	moving_counter -> rra = 0;
	moving_counter -> rb = 0;
	moving_counter -> rrb = 0;
	if (stack_a -> size == 1 || stack_a -> size == 0)
		return ;
	else if (target <= min(stack_a))
		count_command_when_target_is_min(moving_counter, stack_a);
	else if (target >= max(stack_a))
		count_command_when_target_is_max(moving_counter, stack_a);
	else
		count_command_when_general_case(stack_a, target, moving_counter);
	return ;
}

void	count_command_in_stack_b(int idx, t_linked_list *stack_b, \
t_moving_counter *moving_counter)
{
	if (idx == stack_b -> size - 1)
	{
		moving_counter -> rrb = 1;
		moving_counter -> rb = 0;
		return ;
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
	return ;
}

void	update_moving_counter(\
t_moving_counter *min_moving, t_moving_counter *moving_counter)
{
	min_moving -> ra = moving_counter -> ra;
	min_moving -> rra = moving_counter -> rra;
	min_moving -> rb = moving_counter -> rb;
	min_moving -> rrb = moving_counter -> rrb;
}

void	find_minimum_greedy(t_linked_list *stack_a, \
t_linked_list *stack_b, t_moving_counter *min_moving)
{
	t_node				*node;
	t_moving_counter	*moving_counter;
	int					stack_idx;

	stack_idx = 0;
	node = stack_b -> head -> next;
	moving_counter = malloc (sizeof(t_moving_counter));
	count_command_in_stack_a(node -> item, stack_a, min_moving);
	count_command_in_stack_b(stack_idx, stack_b, min_moving);
	stack_idx++;
	node = node -> next;
	while (node != stack_b -> head)
	{
		count_command_in_stack_a(node -> item, stack_a, moving_counter);
		count_command_in_stack_b(stack_idx, stack_b, moving_counter);
		if (sum_moving_counter(min_moving) > sum_moving_counter(moving_counter))
			update_moving_counter(min_moving, moving_counter);
		node = node -> next;
		stack_idx++;
	}
	free(moving_counter);
}
