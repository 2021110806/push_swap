/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_minimum_command_greedy.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:57:27 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/25 22:41:45 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_linked_list *list)
{
	t_node	*node;
	int		i;
	int		ascending;
	int		descending;

	node = list -> head -> next;
	ascending = 1;
	descending = 1;
	while (node != list -> head)
	{
		if (node -> next == list -> head)
			break ;
		if (node -> next -> item > node -> item)
			descending = 0;
		if (node -> next -> item <  node -> item)
			ascending = 0;
		node = node -> next;
	}
	return ((ascending || descending));
}

int count_command_in_stack_a(int target, t_linked_list *stack_a, t_moving_counter *moving_counter)
{
	t_node *node;
	t_moving_counter *sorting_counter = malloc(sizeof(t_moving_counter));
	int		cnt;
	int		min_value;

	cnt = 0;
	node = stack_a -> head -> prev;
	moving_counter -> ra = 0;
	moving_counter -> rra = 0;
	sorting_counter -> ra = 0;
	sorting_counter -> rra = 0;
	sorting_counter -> rb = 0;
	sorting_counter -> rrb = 0;
	if (stack_a -> size == 1 || stack_a -> size == 0)
	{
		moving_counter -> rb = 0;
		moving_counter -> rrb = 0;
		return 1;
	}
	cnt = 0;
	node = stack_a -> head -> next;
	if (target <= min(stack_a))
	{
		while (node != stack_a -> head)
		{
			//printf("node item -> %d\n",node -> item);
			if (node -> item == max(stack_a))
			{
				if (cnt < stack_a -> size / 2)
				{
					moving_counter -> ra = cnt + 1;
					//printf("1: target -> %d, cnt : %d, node -> item: %d, node -> next -> item %d\n",target, cnt, node -> item, node -> next -> item);
					return (1);
				}
				else
				{
					moving_counter -> rra = stack_a -> size - (cnt + 1);
					printf("2: target-> %d, cnt : %d\n",target, cnt);
					return (1);
				}
			}
		cnt++;
		node = node -> next;
		}
	}
	if (target >= max(stack_a))
	{
		while (node != stack_a -> head)
		{
		//printf("node item -> %d\n",node -> item);
		if (node -> item == min(stack_a))
		{
			if (cnt < stack_a -> size / 2)
			{
				moving_counter -> ra = cnt;
				//printf("1: target -> %d, cnt : %d, node -> item: %d, node -> next -> item %d\n",target, cnt, node -> item, node -> next -> item);
				return (1);
			}
			else
			{
				moving_counter -> rra = stack_a -> size - (cnt);
				printf("2: target-> %d, cnt : %d\n",target, cnt);
				return (1);
			}
		}
		cnt++;
		node = node -> next;
		}
	}
	printf("%d\n",stack_a -> head -> prev != stack_a -> head && stack_a -> head -> next != stack_a -> head );
	printf("%d\n",!(node -> item == max(stack_a) && node -> next -> item == min(stack_a)) );
	printf("%d\n",!(node -> item == min(stack_a) && node -> next -> item == max(stack_a)));
	printf("%d\n",((stack_a -> head -> prev -> item > target && stack_a -> head -> next -> item) || (stack_a -> head -> prev -> item < target && stack_a -> head -> next -> item < target)));
	if (stack_a -> head -> prev != stack_a -> head && stack_a -> head -> next != stack_a -> head && \
	/*!(node -> item == max(stack_a) && node -> next -> item == min(stack_a)) && \
	!(node -> item == min(stack_a) && node -> next -> item == max(stack_a)) && \*/
	((stack_a -> head -> prev -> item > target && stack_a -> head -> next -> item < target) || (stack_a -> head -> prev -> item < target && stack_a -> head -> next -> item > target)))
	{
		printf("!!!!!!!!!!!!!!!!!!!!");
		int gap1 = abs_ (stack_a -> head -> prev -> item - stack_a -> head -> next -> item);
		int gap2 = 2147483647;
		node = stack_a -> head -> next;
		while (node != stack_a -> head)
		{
			if (node -> next != stack_a -> head && gap2 > abs_(node -> item - node -> next -> item) && abs_(node -> item - node -> next -> item) != 1)
				gap2 = abs_(node -> item - node -> next -> item);
			node = node -> next;
		}
		printf("gap2 = %d , gap1 = %d\n", gap2, gap1);
		if (gap2 > gap1)
		{
			printf("!!gap!! %d\n", gap1);
			moving_counter -> rb = 0;
			moving_counter -> rrb = 0;
			return 1;
		}
	}
	node  = stack_a -> head -> next;
	while (node != stack_a -> head)
	{
		printf("0 : target -> %d, cnt : %d, node -> item: %d, node -> next -> item %d\n",target, cnt, node -> item, node -> next -> item);
		printf("!@!!@!@!%d %d %d %d\n", node -> item < target, (target < node -> next -> item || node -> next == stack_a -> head), !(node -> item == max(stack_a) && node -> next -> item == min(stack_a)),!(node -> item == min(stack_a) && node -> next -> item == max(stack_a)));
		if ((node -> item < target && (target < node -> next -> item || node -> next == stack_a -> head)) \
		|| (node -> item > target && (target > node -> next -> item || node -> next == stack_a -> head)
		&&!(node -> item == max(stack_a) && node -> next -> item == min(stack_a)) && \
		!(node -> item == min(stack_a) && node -> next -> item == max(stack_a))))
		{
			if (cnt < stack_a -> size / 2)
			{
				moving_counter -> ra = cnt + 1;
				printf("1: target -> %d, cnt : %d, node -> item: %d, node -> next -> item %d\n",target, cnt, node -> item, node -> next -> item);
				printf("ra %d, rra %d, rb %d, rrb %d\n",moving_counter -> ra, moving_counter -> rra, moving_counter -> rb, moving_counter -> rrb);
				return (1);
			}
			else
			{
				moving_counter -> rra = stack_a -> size - (cnt + 1);
				printf("ra %d, rra %d, rb %d, rrb %d\n",moving_counter -> ra, moving_counter -> rra, moving_counter -> rb, moving_counter -> rrb);
				printf("2: target-> %d, cnt : %d\n",target, cnt);
				return (1);
			}
		}
		cnt++;
		node = node -> next;
	}
	cnt--;
	printf("3: target -> %d\n",target);
	printf("??\n");
	printf("ra %d, rra %d, rb %d, rrb %d\n",moving_counter -> ra, moving_counter -> rra, moving_counter -> rb, moving_counter -> rrb);
	return (1);
}

int count_command_in_stack_b(int idx, t_linked_list *stack_b, t_moving_counter *moving_counter)
{
	printf("command b\n");
	if (idx < stack_b -> size / 2)
	{
		moving_counter -> rb = idx;
		moving_counter -> rrb = 0;
	}
	else
	{
		moving_counter -> rrb = stack_b -> size - (idx -1);
		moving_counter -> rb = 0;
	}
	printf("ra %d, rra %d, rb %d, rrb %d\n",moving_counter -> ra, moving_counter -> rra, moving_counter -> rb, moving_counter -> rrb);
	return (1);
}

t_moving_counter	*find_minimum_greedy(t_linked_list *stack_a, t_linked_list *stack_b)
{
	t_node 			*node;
	t_moving_counter *moving_counter;
	t_moving_counter *min_moving;
	int				stack_idx;

	stack_idx = 0;
	node = stack_b -> head -> next;
	moving_counter = malloc (sizeof(t_moving_counter));
	min_moving = malloc (sizeof(t_moving_counter));
	printf("<node -> item : %d\n", node -> item);
	count_command_in_stack_a(node -> item, stack_a, moving_counter);
	printf("<node -> item : %d\n", node -> item);
	count_command_in_stack_b(stack_idx, stack_b, moving_counter);
	min_moving -> ra = moving_counter -> ra;
	min_moving -> rra = moving_counter -> rra;
	min_moving -> rb = moving_counter -> rb;
	min_moving -> rrb = moving_counter -> rrb;
	printf("choice : %d\n",node -> item);
	printf("ra %d, rra %d, rb %d, rrb %d\n",moving_counter -> ra, moving_counter -> rra, moving_counter -> rb, moving_counter -> rrb);
	printf("ra %d, rra %d, rb %d, rrb %d\n",min_moving -> ra, min_moving -> rra, min_moving -> rb,min_moving -> rrb);
	if (min_moving -> rra + min_moving -> ra + min_moving -> rb + min_moving -> rrb \
			> moving_counter -> rra + moving_counter -> ra + moving_counter -> rb + moving_counter -> rrb)
		{
			min_moving -> ra = moving_counter -> ra;
			min_moving -> rra = moving_counter -> rra;
			min_moving -> rb = moving_counter -> rb;
			min_moving -> rrb = moving_counter -> rrb;
			printf("choice : %d\n",node -> item);
			printf("ra %d, rra %d, rb %d, rrb %d\n",moving_counter -> ra, moving_counter -> rra, moving_counter -> rb, moving_counter -> rrb);
			printf("ra %d, rra %d, rb %d, rrb %d\n",min_moving -> ra, min_moving -> rra, min_moving -> rb,min_moving -> rrb);
		}
	stack_idx++;
	while (node != stack_b -> head)
	{
		printf("<node -> item : %d\n", node -> item);
		count_command_in_stack_a(node -> item, stack_a, moving_counter);
		printf("<node -> item : %d\n", node -> item);
		count_command_in_stack_b(stack_idx, stack_b, moving_counter);
		if (min_moving -> rra + min_moving -> ra + min_moving -> rb + min_moving -> rrb \
			> moving_counter -> rra + moving_counter -> ra + moving_counter -> rb + moving_counter -> rrb)
		{
			min_moving -> ra = moving_counter -> ra;
			min_moving -> rra = moving_counter -> rra;
			min_moving -> rb = moving_counter -> rb;
			min_moving -> rrb = moving_counter -> rrb;
			printf("choice : %d\n",node -> item);
			printf("ra %d, rra %d, rb %d, rrb %d\n",moving_counter -> ra, moving_counter -> rra, moving_counter -> rb, moving_counter -> rrb);
			printf("ra %d, rra %d, rb %d, rrb %d\n",min_moving -> ra, min_moving -> rra, min_moving -> rb,min_moving -> rrb);
		}
		node = node -> next;
		stack_idx++;
	}
	return (min_moving);
}