/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:55:00 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/19 23:37:26 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	sa(t_linked_list *stack_a)
{
	t_node	*head_prev;
	t_node	*head_prev_prev;

	if (!stack_a || stack_a -> size == 0 || stack_a -> size == 1)
		return (0);
	head_prev = make_new_node(get_last(stack_a));
	delete_last(stack_a);
	head_prev_prev = make_new_node(get_last(stack_a));
	delete_last(stack_a);
	add_last(stack_a, head_prev);
	add_last(stack_a, head_prev_prev);
	write(1,"sa\n",3);
	return (1);
}

int	sb(t_linked_list *stack_b)
{
	t_node	*head_prev;
	t_node	*head_prev_prev;

	if (!stack_b || stack_b -> size == 0 || stack_b -> size == 1)
		return (0);
	head_prev = make_new_node(get_last(stack_b));
	delete_last(stack_b);
	head_prev_prev = make_new_node(get_last(stack_b));
	delete_last(stack_b);
	add_last(stack_b, head_prev);
	add_last(stack_b, head_prev_prev);
	write(1,"sb\n",3);
	return (1);
}

int	ss(t_linked_list *stack_a, t_linked_list *stack_b)
{
	if (!sa(stack_a))
		return (0);
	if (!sb(stack_b))
		return (0);
	write(1,"ss\n",3);
	return (1);
}
