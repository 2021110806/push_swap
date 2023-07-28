/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioning_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:13:53 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/29 06:03:15 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_of_over_pivot_l(t_linked_list *list, int pivot_l)
{
	t_node	*node;
	int		size;

	size = 0;
	node = list -> head -> next;
	while (node != list -> head)
	{
		if (node -> item > pivot_l)
			size++;
		node = node -> next;
	}
	return (size);
}

void	move_nodes_over_pivot_l(t_linked_list *stack_a, t_linked_list *stack_b)
{
	t_node	*node;

	node = stack_a -> head -> next;
	while (node != stack_a -> head)
	{
		node = stack_a -> head -> next;
		pb(stack_a, stack_b);
	}
	return ;
}

void	partition(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int		pivot_s;
	int		pivot_l;
	t_node	*node;

	pivot_s = (min(stack_a) + max(stack_a)) / 3;
	pivot_l = (min(stack_a) + max(stack_a)) / 3 * 2;
	while (stack_a -> size > size_of_over_pivot_l(stack_a, pivot_l))
	{
		node = stack_a -> head -> next;
		if (pivot_s < node -> item && node -> item <= pivot_l)
			pb(stack_a, stack_b);
		else if (pivot_l < node -> item)
			ra(stack_a, 0);
		else if (pivot_s >= node -> item)
		{
			pb(stack_a, stack_b);
			rb(stack_b, 0);
		}
	}
	move_nodes_over_pivot_l(stack_a, stack_b);
	return ;
}
