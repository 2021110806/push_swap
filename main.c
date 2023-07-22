/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:16:25 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/23 01:29:04 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	int				i;
	long long		num;
	t_node			*node;
	t_linked_list *stack_a;
	t_linked_list *stack_b;
	t_moving_counter *min_moving;

	i = 1;
	stack_a = make_new_list();
	stack_b = make_new_list();
	min_moving = malloc (sizeof (t_moving_counter));
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 12)
			return (error());
		num = (long long) ft_atoi(argv[i]);
		if (!(num <= 2147483647 && num >= -2147483648))
			return (error());
		node = make_new_node((int) num);
		add_last(stack_a, node);
		i++;
	}
	make_stack_to_idx(stack_a);
	partition(stack_a, stack_b);
	node = stack_b -> head -> prev;
	while (node != stack_b -> head)
	{
		min_moving = find_minimum_greedy(stack_a, stack_b);
		rotate(stack_a, stack_b, min_moving);
		reverse_rotate(stack_a, stack_b, min_moving);
		pa(stack_a, stack_b);
		node = stack_b -> head -> prev;
	}
	print_all(stack_a);
}