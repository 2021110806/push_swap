/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:55:47 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/27 19:32:27 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 
#include <stdio.h>
int	rra(t_linked_list *stack_a, int is_rrr)
{
	t_node *node;

	if (!stack_a || stack_a -> size == 0 || stack_a -> size == 1)
		return (0);
	node = make_new_node(get_last(stack_a));
	delete_last(stack_a);
	add_first(stack_a, node);
	if (!is_rrr)
		write(1,"rra\n",4);
	return (1);
}

int	rrb(t_linked_list *stack_b, int is_rrr)
{
	t_node *node;

	if (!stack_b || stack_b -> size == 0 || stack_b -> size == 1)
		return (0);
	node = make_new_node(get_last(stack_b));
	delete_last(stack_b);
	add_first(stack_b, node);
	if (!is_rrr)
		write(1,"rrb\n",4);
	return (1);
}

int	rrr(t_linked_list *stack_a, t_linked_list *stack_b)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	write(1,"rrr\n",4);
	return (1);
}
