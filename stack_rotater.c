/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:36:26 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/22 21:56:03 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 #include <stdio.h>
int	rotate(t_linked_list *stack_a, t_linked_list *stack_b, t_moving_counter *moving_counter)
{
	while (moving_counter -> ra > 0 && moving_counter -> rb > 0)
	{
		rr(stack_a, stack_b);
		moving_counter -> ra--;
		moving_counter -> rb--;
	}
	while (moving_counter -> ra > 0)
	{
		ra(stack_a);
		moving_counter -> ra--;
	}
	while (moving_counter -> rb > 0)
	{
		rb(stack_b);
		moving_counter -> rb--;
	}
	return (1);
}

int	reverse_rotate(t_linked_list *stack_a, t_linked_list *stack_b, t_moving_counter *moving_counter)
{
	while (moving_counter -> ra > 0 && moving_counter -> rb > 0)
	{
		rrr(stack_a, stack_b);
		moving_counter -> rra--;
		moving_counter -> rrb--;
	}
	while (moving_counter -> rra > 0)
	{
		rra(stack_a);
		moving_counter -> rra--;
	}
	while (moving_counter -> rrb > 0)
	{
		rrb(stack_b);
		moving_counter -> rrb--;
	}
	return (1);
}

int rotate_stack_a(t_linked_list *stack_a, t_moving_counter *moving_counter)
{
	while (moving_counter -> ra > 0)
	{
		ra(stack_a);
		moving_counter -> ra--;
	}
	while (moving_counter -> rra > 0)
	{
		rra(stack_a);
		moving_counter -> rra--;
	}
	return (1);
}
