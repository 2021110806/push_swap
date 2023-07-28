/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:20:17 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/29 00:27:09 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(int argc, char **argv, int idx)
{
	int	j;

	if (argv[idx])
	{
		j = 0;
		while (argv[idx][j])
		{
			if (!ft_isdigit((int) argv[idx][j]))
				return (0);
			j++;
		}
	}
	return (1);
}

int	is_valid_input(char **argv, int argc, t_linked_list *stack_a)
{
	int			i;
	int			j;
	long long	num;
	t_node		*node;

	i = 1;
	if (argc == 1)
		return (error());
	while (i < argc)
	{
		if (!is_digit(argc, argv, i))
			return (error());
		if (ft_strlen(argv[i]) > 12)
			return (error());
		num = (long long) ft_atoi(argv[i]);
		if (!(num <= 2147483647 && num >= -2147483648))
			return (error());
		node = make_new_node((int) num);
		add_last(stack_a, node);
		i++;
	}
	return (1);
}
