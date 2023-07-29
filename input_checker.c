/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:20:17 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/29 22:27:26 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char **argv, int idx)
{
	int	j;

	if (argv[idx])
	{
		j = 0;
		if (!argv[idx][j])
			return (0);
		while (argv[idx][j])
		{
			if (argv[idx][j] == '-')
			{
				if (j != 0)
					return (0);
				if (ft_strlen(argv[idx]) == 1)
					return (0);
			}
			else
			{
				if (!ft_isdigit((int) argv[idx][j]))
					return (0);
			}
			j++;
		}
	}
	return (1);
}

int	is_duplicate(t_linked_list *stack_a, int target)
{
	t_node	*node;

	node = stack_a -> head -> next;
	while (node != stack_a -> head)
	{
		if (node -> item == target)
			return (1);
		node = node -> next;
	}
	return (0);
}

int	is_valid_input(char **argv, int argc, t_linked_list *stack_a)
{
	int			i;
	long long	num;
	t_node		*node;

	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (!is_digit(argv, i))
			return (error());
		if (ft_strlen(argv[i]) > 12)
			return (error());
		num = (long long) ft_atoi(argv[i]);
		if (!(num <= 2147483647 && num >= -2147483648))
			return (error());
		if (is_duplicate(stack_a, (int) num))
			return (error());
		node = make_new_node((int) num);
		add_last(stack_a, node);
		i++;
	}
	return (1);
}
