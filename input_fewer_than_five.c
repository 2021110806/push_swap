/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_fewer_than_five.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 06:52:54 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/29 22:09:56 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_when_size_is_two(t_linked_list *stack_a)
{
	if (!stack_a)
		return (1);
	if (stack_a -> head -> prev < stack_a -> head -> next -> next)
		sa(stack_a);
	return (1);
}

int	sort_when_size_is_three(t_linked_list *stack_a)
{
	t_node	*head;

	head = stack_a -> head;
	if (head -> next -> item < head -> prev -> item && \
		head -> next -> item < head -> next -> next -> item)
		sort_when_next_is_smallest(stack_a);
	else if (head -> prev -> item < head -> next -> item && \
		head -> prev -> item < head -> next -> next -> item)
		sort_when_prev_is_smallest(stack_a);
	else
	{
		if (head -> prev -> item > head -> next -> item)
			sa(stack_a);
		else
			ra(stack_a, 0);
	}
	return (1);
}

int	sort_when_size_is_four(t_linked_list *stack_a, t_linked_list *stack_b)
{
	if (!stack_a)
		return (1);
	move_min_value_to_top(stack_a);
	pb(stack_a, stack_b);
	sort_when_size_is_three(stack_a);
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
	sort_when_size_is_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	return (1);
}

int	sort_when_input_is_few(t_linked_list *stack_a, t_linked_list *stack_b)
{
	if (stack_a -> size == 2)
		return (sort_when_size_is_two(stack_a));
	if (stack_a -> size == 3)
		return (sort_when_size_is_three(stack_a));
	if (stack_a -> size == 4)
		return (sort_when_size_is_four(stack_a, stack_b));
	if (stack_a -> size == 5)
		return (sort_when_size_is_five(stack_a, stack_b));
	return (0);
}
