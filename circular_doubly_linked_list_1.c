/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_doubly_linked_list_1.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:10:51 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/27 22:20:59 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_linked_list	*make_new_list(void)
{
	t_linked_list	*list;
	t_node			*head;

	list = malloc (sizeof(t_linked_list));
	if (!list)
		return (0);
	head = make_new_node(0);
	head -> next = head;
	head -> prev = head;
	list -> head = head;
	list -> size = 0;
	return (list);
}

t_node	*make_new_node(int item)
{
	t_node	*node;

	node = malloc (sizeof(t_node));
	if (!node)
		return (0);
	node -> item = item;
	node -> prev = node;
	node -> next = node;
	return (node);
}

int	add_first(t_linked_list *list, t_node *new_node)
{
	t_node	*head;

	if (!list || !new_node)
		return (0);
	head = list->head;
	head->next->prev = new_node;
	new_node->next = head -> next;
	new_node->prev = head;
	head -> next = new_node;
	list -> size += 1;
	return (1);
}

int	add_last(t_linked_list *list, t_node *new_node)
{
	t_node	*head;

	if (!list | !new_node)
		return (0);
	head = list -> head;
	new_node -> next = head;
	head -> prev -> next = new_node;
	new_node -> prev = head -> prev;
	head -> prev = new_node;
	list -> size += 1;
	return (1);
}

int	print_all(t_linked_list *list)
{
	t_node	*node;
	int		size;
	int		i;

	if (!list)
		return (0);
	i = 0;
	size = list -> size;
	node = list -> head -> next;
	while (i < size)
	{
		ft_putnbr_fd(node -> item, 1);
		ft_putstr_fd("\n", 1);
		node = node -> next;
		i++;
	}
	return (1);
}
