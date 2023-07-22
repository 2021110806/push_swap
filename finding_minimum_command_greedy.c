/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_minimum_command_greedy.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:57:27 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/23 01:18:08 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_linked_list *list)
{
	t_node	*node;
	int		i;
	int		ascending;
	int		descending;

	node = list -> head -> next;
	ascending = 1;
	descending = 1;
	while (node != list -> head)
	{
		if (node -> next == list -> head)
			break ;
		if (node -> next -> item > node -> item)
			descending = 0;
		if (node -> next -> item <  node -> item)
			ascending = 0;
		node = node -> next;
	}
	return ((ascending || descending));
}

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
	if (!is_sorted(stack_a))
	{
		min_value = min(stack_a);
		while (node -> item != min_value)
		{
			node = node -> prev;
			cnt++;
		}
		if (cnt <= stack_a -> size / 2)
		{
			sorting_counter -> ra = cnt + 1;
			sorting_counter -> rra = 0;
		}
		else
		{
			sorting_counter -> rra = stack_a -> size - (cnt + 1);
			sorting_counter -> ra = 0;
		}
	}
		cnt = 0;
		node = stack_a -> head -> prev;
		rotate_stack_a(stack_a, sorting_counter);
		node = stack_a -> head -> prev;
		while (node != stack_a -> head)
		{
			if ((node -> item > target && (target > node -> prev -> item || node -> prev == stack_a -> head)) || \
				(node -> item < target && (target < node -> prev -> item || node -> prev == stack_a -> head)))
			{
				if (cnt < stack_a -> size / 2)
				{
					moving_counter -> ra += cnt + 1;
					break;
				}
				else
				{
					moving_counter -> rra += stack_a -> size - (cnt + 1);
					break ;
				}
			}
			cnt++;
			node = node -> prev;
		}
	cnt--;
	return (1);
}

int count_command_in_stack_b(int idx, t_linked_list *stack_b, t_moving_counter *moving_counter)
{
	if (idx > stack_b -> size)
	{
		moving_counter -> rrb = idx - 1;
		moving_counter -> rb = 0;
	}
	else
	{
		moving_counter -> rb = stack_b -> size - idx;
		moving_counter -> rrb = 0;
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
	if (min_moving -> rra + min_moving -> ra + min_moving -> rb + min_moving -> rrb \
			> moving_counter -> rra + moving_counter -> ra + moving_counter -> rb + moving_counter -> rrb)
		{
			min_moving -> ra = moving_counter -> ra;
			min_moving -> rra = moving_counter -> rra;
			min_moving -> rb = moving_counter -> rb;
			min_moving -> rrb = moving_counter -> rrb;
		}
	stack_idx++;
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