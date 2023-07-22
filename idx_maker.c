/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:57:40 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/19 23:38:56 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size -1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	make_stack_to_idx(t_linked_list *list)
{
	t_node *node;
	int		*dct;
	int		i;

	node =  list -> head -> next;
	dct = malloc (sizeof (int) * list -> size);
	i = 0;
	while (node != list -> head)
	{
		dct[i] = node -> item;
		i++;
		node = node -> next;
	}
	sort(dct, list -> size);
	node = list -> head -> next;
	while (node != list -> head)
	{
		i = 0;
		while (i < list -> size)
		{
			if (dct[i] == node -> item)
			{
				node -> item = i;
				break ;
			}
			i++;
		}
		node = node -> next;
	}
	free(dct);
	return (1);
}
