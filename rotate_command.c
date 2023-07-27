/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:55:25 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/27 19:31:14 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	ra(t_linked_list *stack_a, int is_rr)
{
	t_node	*node;

	if (!stack_a || stack_a -> size == 0 || stack_a -> size == 1)
		return (0);
	node = make_new_node(get_first(stack_a));
	if (!node)
		return (0);
	delete_first(stack_a);
	add_last(stack_a, node);
	if (!is_rr)
		write(1,"ra\n",3);
	return (1);
}

int	rb(t_linked_list *stack_b, int is_rr)
{
	t_node	*node;
	int		item;

	if (!stack_b || stack_b -> size == 0 || stack_b -> size == 1)
		return (0);
	node = make_new_node(get_first(stack_b));
	if (!node)
		return (0);
	delete_first(stack_b);
	add_last(stack_b, node);
	if (!is_rr)
		write(1,"rb\n",3);
	return (1);
}

int	rr(t_linked_list *stack_a, t_linked_list *stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	write(1,"rr\n",3);
	return (1);
}
