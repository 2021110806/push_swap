/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioning_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:13:53 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/27 19:43:04 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	ft_putstr_fd("Error", 1);
	return (0);
}

int	max(t_linked_list *list)
{
	int		i;
	int 	max_value;
	t_node	*node;

	i = 0;
	max_value = -2147483648;
	node = list -> head;
	node = node -> next;
	while (i < list -> size)
	{
		if (node -> item > max_value)
			max_value = node -> item;
		i++;
		node = node -> next;
	}
	return (max_value);
}

int	min(t_linked_list *list)
{
	int	i;
	int min_value;
	t_node	*node;

	i = 0;
	min_value = 2147483647;
	node = list -> head;
	node = node -> next;
	while (i < list -> size)
	{
		if (node -> item < min_value)
			min_value = node -> item;
		i++;
		node = node -> next;
	}
	return (min_value);
}

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

int partition(t_linked_list *stack_a, t_linked_list *stack_b)
{
	int		pivot_s;
	int		pivot_l;
	int		cnt;
	int		limit;
	int		tmp;
	t_node *node;

	pivot_s = (min(stack_a) + max(stack_a)) / 3;
	pivot_l = (min(stack_a) + max(stack_a)) / 3 * 2;
	cnt = 0;
	limit = stack_a -> size;
	node = stack_a -> head -> next;
	while (stack_a -> size > size_of_over_pivot_l(stack_a, pivot_l))
	{
		node = stack_a -> head -> next;
		if (pivot_s < node -> item && node -> item <= pivot_l)
			pb(stack_a, stack_b);
		if (pivot_l < node -> item)
			ra(stack_a, 0);
		if (pivot_s >= node -> item)
		{
			pb(stack_a, stack_b);
			rb(stack_b, 0);
		}
		cnt++;
	}
	node = stack_a -> head -> next;
	while (node != stack_a -> head)
	{
		pb(stack_a, stack_b);
		node = node -> next;
	}
	return (1);
}