/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 00:09:22 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/30 03:41:46 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_command_when_target_is_min(\
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
				return ;
			}
			else
			{
				moving_counter -> rra = stack_a -> size - (cnt + 1);
				return ;
			}
		}
	cnt++;
	node = node -> next;
	}
}

void	count_command_when_target_is_max(\
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
				return ;
			}
			else
			{
				moving_counter -> rra = stack_a -> size - (cnt);
				return ;
			}
		}
	cnt++;
	node = node -> next;
	}
}

void	count_command_when_general_case(t_linked_list *stack_a, int target, \
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
			return ;
		}
		cnt++;
		node = node -> next;
	}
}
