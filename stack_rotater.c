/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:36:26 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/27 22:11:08 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_linked_list *stack_a, t_linked_list *stack_b, \
t_moving_counter *moving_counter)
{
	while (moving_counter -> ra > 0 && moving_counter -> rb > 0)
	{
		rr(stack_a, stack_b);
		moving_counter -> ra--;
		moving_counter -> rb--;
	}
	while (moving_counter -> ra > 0)
	{
		ra(stack_a, 0);
		moving_counter -> ra--;
	}
	while (moving_counter -> rb > 0)
	{
		rb(stack_b, 0);
		moving_counter -> rb--;
	}
	return (1);
}

int	reverse_rotate(t_linked_list *stack_a, t_linked_list *stack_b, \
t_moving_counter *moving_counter)
{
	while (moving_counter -> ra > 0 && moving_counter -> rb > 0)
	{
		rrr(stack_a, stack_b);
		moving_counter -> rra--;
		moving_counter -> rrb--;
	}
	while (moving_counter -> rra > 0)
	{
		rra(stack_a, 0);
		moving_counter -> rra--;
	}
	while (moving_counter -> rrb > 0)
	{
		rrb(stack_b, 0);
		moving_counter -> rrb--;
	}
	return (1);
}

int	move_min_value_to_top(t_linked_list *stack_a)
{
	int		min_value;
	int		cnt;
	t_node	*node;

	cnt = find_distance_to_min_value(stack_a);
	min_value = min(stack_a);
	if (cnt < stack_a -> size / 2)
	{
		cnt ++;
		while (--cnt)
			ra(stack_a, 0);
		return (1);
	}
	cnt = stack_a -> size - cnt;
	cnt ++;
	while (--cnt)
	{
		rra(stack_a, 0);
		cnt--;
	}
	return (1);
}
