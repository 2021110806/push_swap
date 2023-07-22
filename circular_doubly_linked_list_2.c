/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_doubly_linked_list_2.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:11:34 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/18 22:41:04 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	delete_last(t_linked_list *list)
{	
	t_node	*head;
	t_node	*node_saver;

	if (!list)
		return (0);
	head = list -> head;
	// if (list -> size == 1)
	// {
	// 	free(list -> head);
	// 	return (1);
	// }
	node_saver = head -> prev;
	head -> prev -> prev -> next = head;
	head -> prev = head -> prev -> prev;
	free(node_saver);
	list -> size -= 1;
	return (1);
}

int	delete_first(t_linked_list *list)
{
	t_node *head;
	t_node *node_saver;

	if (!list)
		return (0);
	head = list -> head;
	node_saver = head -> next;
	// if (list -> size == 1)
	// {
	// 	free(list -> head);
	// 	return (1);
	// }
	head -> next -> next -> prev = head;
	head -> next = head -> next -> next;
	free(node_saver);
	list -> size -= 1;
	return (1);
}

int get_first(t_linked_list *list)
{
	t_node *head;
	t_node *node;

	head = list -> head;
	node = head -> next;
	return (node -> item);
}

int get_last(t_linked_list *list)
{
	t_node *head;
	t_node *node;

	head = list -> head;
	node = head -> prev;
	return (node -> item);
}