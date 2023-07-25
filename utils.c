#include "push_swap.h"

int	abs_(int inp)
{
	if (inp < 0)
		return (-1 * inp);
	return (inp);
}

int move_min_value_to_top(t_linked_list *stack_a)
{
	int 	min_value;
	int		cnt;
	t_node *node;

	cnt = 0;
	min_value = min(stack_a);
	node = stack_a -> head -> next;
	while (node -> item != min_value)
	{
		cnt++;
		node = node -> next;
	}
	if (cnt < stack_a -> size / 2)
	{
		while (cnt)
		{
			ra(stack_a);
			cnt--;
		}
	}
	else
	{
		cnt = stack_a -> size - cnt;
		while (cnt)
		{
			rra(stack_a);
			cnt--;
		}
	}
	return (1);
}