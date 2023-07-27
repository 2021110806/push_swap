/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_minimum_command_greedy.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:57:27 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/27 21:13:14 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_command_in_stack_a(int target, t_linked_list *stack_a, t_moving_counter *moving_counter)
{
	t_node *node;
	t_moving_counter *sorting_counter = malloc(sizeof(t_moving_counter));
	int		cnt;
	int		min_value;

	cnt = 0;
	node = stack_a -> head -> prev;
	moving_counter -> ra = 0;
	moving_counter -> rra = 0;
	sorting_counter -> ra = 0;
	sorting_counter -> rra = 0;
	sorting_counter -> rb = 0;
	sorting_counter -> rrb = 0;
	if (stack_a -> size == 1 || stack_a -> size == 0)
	{
		moving_counter -> rb = 0;
		moving_counter -> rrb = 0;
		return 1;
	}
	cnt = 0;
	node = stack_a -> head -> next;
	if (target <= min(stack_a))
	{
		while (node != stack_a -> head)
		{
			if (node -> item == max(stack_a))
			{
				if (cnt < stack_a -> size / 2)
				{
					moving_counter -> ra = cnt + 1;
					return (1);
				}
				else
				{
					moving_counter -> rra = stack_a -> size - (cnt + 1);
					return (1);
				}
			}
		cnt++;
		node = node -> next;
		}
	}
	if (target >= max(stack_a))
	{
		while (node != stack_a -> head)
		{
			if (node -> item == min(stack_a))
			{
				if (cnt < stack_a -> size / 2)
				{
					moving_counter -> ra = cnt;
					return (1);
				}
				else
				{
					moving_counter -> rra = stack_a -> size - (cnt);
					return (1);
				}
			}
		cnt++;
		node = node -> next;
		}
	}
	if (stack_a -> head -> prev != stack_a -> head && stack_a -> head -> next != stack_a -> head && \
	((stack_a -> head -> prev -> item > target && stack_a -> head -> next -> item < target) || (stack_a -> head -> prev -> item < target && stack_a -> head -> next -> item > target)))
	{
		int gap1 = abs_ (stack_a -> head -> prev -> item - stack_a -> head -> next -> item);
		int gap2 = 2147483647;
		node = stack_a -> head -> next;
		while (node != stack_a -> head)
		{
			if (node -> next != stack_a -> head && gap2 > abs_(node -> item - node -> next -> item) && abs_(node -> item - node -> next -> item) != 1)
				gap2 = abs_(node -> item - node -> next -> item);
			node = node -> next;
		}
		if (gap2 > gap1)
		{
			moving_counter -> rb = 0;
			moving_counter -> rrb = 0;
			return 1;
		}
	}
	node  = stack_a -> head -> next;
	while (node != stack_a -> head)
	{
		if ((node -> item < target && (target < node -> next -> item || node -> next == stack_a -> head)) \
		|| (node -> item > target && (target > node -> next -> item || node -> next == stack_a -> head)
		&&!(node -> item == max(stack_a) && node -> next -> item == min(stack_a)) && \
		!(node -> item == min(stack_a) && node -> next -> item == max(stack_a))))
		{
			if (cnt < stack_a -> size / 2)
			{
				moving_counter -> ra = cnt + 1;
				return (1);
			}
			else
			{
				moving_counter -> rra = stack_a -> size - (cnt + 1);
				return (1);
			}
		}
		cnt++;
		node = node -> next;
	}
	cnt--;
	return (1);
}

int count_command_in_stack_b(int idx, t_linked_list *stack_b, t_moving_counter *moving_counter)
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

t_moving_counter	*find_minimum_greedy(t_linked_list *stack_a, t_linked_list *stack_b)
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