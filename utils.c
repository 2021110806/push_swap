/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:34:42 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/29 02:40:57 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs_(int inp)
{
	if (inp < 0)
		return (-1 * inp);
	return (inp);
}

int	min(t_linked_list *list)
{
	int		i;
	int		min_value;
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

int	max(t_linked_list *list)
{
	int		i;
	int		max_value;
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

int	is_sorted(t_linked_list *list)
{
	t_node	*node;
	int		i;
	int		ascending;

	node = list -> head -> next;
	ascending = 1;
	while (node != list -> head)
	{
		if (node -> next == list -> head)
			break ;
		if (node -> next -> item < node -> item)
			ascending = 0;
		node = node -> next;
	}
	return ((ascending));
}

int	find_distance_to_min_value(t_linked_list *stack_a)
{
	t_node	*node;
	int		cnt;
	int		min_value;

	cnt = 0;
	min_value = min(stack_a);
	node = stack_a -> head -> next;
	while (node -> item != min_value)
	{
		cnt++;
		node = node -> next;
	}
	return (cnt);
}
