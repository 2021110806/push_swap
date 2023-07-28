/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 00:09:22 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/29 00:33:16 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_command_when_target_is_min(int target, \
					t_moving_counter *moving_counter, t_linked_list *stack_a)
{
	int		cnt;
	t_node	*node;

	cnt = 0;
	node = stack_a -> head -> next;
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
	return (1);
}

int	count_command_when_target_is_max(int target, \
		t_moving_counter *moving_counter, t_linked_list *stack_a)
{
	t_node	*node;
	int		cnt;

	cnt = 0;
	node = stack_a -> head -> next;
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
	return (1);
}

int	count_command_when_target_is_top(int target,
	t_moving_counter *moving_counter, t_linked_list *stack_a)
{
	t_node	*node;
	int		gap1;
	int		gap2;

	gap1 = abs_ (stack_a->head->prev->item - stack_a->head->next->item);
	gap2 = 2147483647;
	node = stack_a -> head -> next;
	while (node != stack_a -> head)
	{
		if (node -> next != stack_a -> head && gap2 > \
		abs_(node -> item - node -> next -> item) && \
		abs_(node -> item - node -> next -> item) != 1)
			gap2 = abs_(node -> item - node -> next -> item);
		node = node -> next;
	}
	if (gap2 > gap1)
	{
		moving_counter -> rb = 0;
		moving_counter -> rrb = 0;
		return (1);
	}
	return (0);
}

int	count_command_when_general_case(t_linked_list *stack_a, int target, \
										t_moving_counter *moving_counter)
{
	t_node	*node;
	int		cnt;

	cnt = 0;
	node = stack_a -> head -> next;
	while (node != stack_a -> head)
	{
		if ((node -> item < target && (target < node -> next -> item || node -> \
		next == stack_a -> head)) || (node -> item > target && (target > node \
		-> next -> item || node -> next == stack_a -> head) &&!(node -> item \
		== max(stack_a) && node -> next -> item == min(stack_a)) && !(node \
		-> item == min(stack_a) && node -> next -> item == max(stack_a))))
		{
			if (cnt < stack_a -> size / 2)
				moving_counter -> ra = cnt + 1;
			else
				moving_counter -> rra = stack_a -> size - (cnt + 1);
			return (1);
		}
		cnt++;
		node = node -> next;
	}
	return (1);
}
