/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:55:47 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/23 22:49:11 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 
#include <stdio.h>
int	rra(t_linked_list *stack_a)
{
	t_node *node;

	if (!stack_a || stack_a -> size == 0 || stack_a -> size == 1)
		return (0);
	node = make_new_node(get_last(stack_a));
	delete_last(stack_a);
	add_first(stack_a, node);
	write(1,"rra\n",4);
	return (1);
}

int	rrb(t_linked_list *stack_b)
{
	t_node *node;

	if (!stack_b || stack_b -> size == 0 || stack_b -> size == 1)
		return (0);
	node = make_new_node(get_last(stack_b));
	delete_last(stack_b);
	add_first(stack_b, node);
	write(1,"rrb\n",4);
	return (1);
}

int	rrr(t_linked_list *stack_a, t_linked_list *stack_b)
{
	if (!rra(stack_a))
		return (0);
	if (!rrb(stack_b))
		return (0);
	write(1,"rrr\n",4);
	return (1);
}
