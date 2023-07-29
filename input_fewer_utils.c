/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_fewer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:10:28 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/29 22:15:28 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_when_next_is_smallest(t_linked_list *stack_a)
{
	ra(stack_a, 0);
	sa(stack_a);
	rra(stack_a, 0);
}

void	sort_when_prev_is_smallest(t_linked_list *stack_a)
{
	t_node	*head;

	head = stack_a -> head;
	if (head -> next -> next -> item < head -> next -> item)
	{
		sa(stack_a);
		rra(stack_a, 0);
	}
	else
		rra(stack_a, 0);
}
