/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:56:09 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/29 03:18:41 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_linked_list *stack_a, t_linked_list *stack_b)
{
	t_node	*node;

	if (!stack_a || !stack_b || stack_b -> size == 0)
		return (0);
	node = make_new_node(get_first(stack_b));
	delete_first(stack_b);
	add_first(stack_a, node);
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_linked_list *stack_a, t_linked_list *stack_b)
{
	t_node	*node;

	if (!stack_a || !stack_b || stack_a -> size == 0)
		return (0);
	node = make_new_node(get_first(stack_a));
	delete_first(stack_a);
	add_first(stack_b, node);
	write(1, "pb\n", 3);
	return (1);
}
