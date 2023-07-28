/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_fewer_than_five.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 06:52:54 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/29 08:25:58 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_when_size_is_two(t_linked_list *stack_a)
{
	if (!stack_a)
		return (1);
	if (stack_a -> head -> next < stack_a -> head -> prev)
		sa(stack_a);
	return (1);
}

int	sort_when_size_is_three(t_linked_list *stack_a, t_linked_list *stack_b)
{
	if (!stack_a)
		return (1);
	move_min_value_to_top(stack_a);
	pb(stack_a, stack_b);
	sort_when_size_is_two(stack_a);
	pa(stack_a, stack_b);
	return (1);
}

int	sort_when_size_is_four(t_linked_list *stack_a, t_linked_list *stack_b)
{
	if (!stack_a)
		return (1);
	move_min_value_to_top(stack_a);
	pb(stack_a, stack_b);
	sort_when_size_is_three(stack_a, stack_b);
	pa(stack_a, stack_b);
	return (1);
}

int	sort_when_size_is_five(t_linked_list *stack_a, t_linked_list *stack_b)
{
	if (!stack_a)
		return (1);
	move_min_value_to_top(stack_a);
	pb(stack_a, stack_b);
	move_min_value_to_top(stack_a);
	pb(stack_a, stack_b);
	sort_when_size_is_three(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	return (1);
}

int	sort_when_input_is_few(t_linked_list *stack_a, t_linked_list *stack_b)
{
	if (stack_a -> size == 2)
		return (sort_when_size_is_two(stack_a));
	if (stack_a -> size == 3)
		return (sort_when_size_is_three(stack_a, stack_b));
	if (stack_a -> size == 4)
		return (sort_when_size_is_four(stack_a, stack_b));
	if (stack_a -> size == 5)
		return (sort_when_size_is_five(stack_a, stack_b));
	return (0);
}
