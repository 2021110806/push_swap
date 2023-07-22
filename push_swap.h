/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:59:56 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/22 21:56:14 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				item;
}	t_node;

typedef struct s_linked_list
{
	t_node	*head;
	int		size;
}	t_linked_list;

typedef struct s_moving_counter
{
	int	rb;
	int	rrb;
	int	ra;
	int	rra;
}	t_moving_counter;

t_linked_list	*make_new_list(void);
t_node			*make_new_node(int item);
int				add_first(t_linked_list *list, t_node *new_node);
int				add_last(t_linked_list *list, t_node *new_node);
int				print_all(t_linked_list *list);
int				delete_last(t_linked_list *list);
int				delete_first(t_linked_list *list);
int				pa(t_linked_list *stack_a, t_linked_list *stack_b);
int				pb(t_linked_list *stack_a, t_linked_list *stack_b);
int				ra(t_linked_list *stack_a);
int				rb(t_linked_list *stack_b);
int				rr(t_linked_list *stack_a, t_linked_list *stack_b);
int				rrb(t_linked_list *stack_b);
int				rra(t_linked_list *stack_a);
int				rrr(t_linked_list *stack_a, t_linked_list *stack_b);
int				sa(t_linked_list *stack_a);
int				sb(t_linked_list *stack_b);
int				ss(t_linked_list *stack_a, t_linked_list *stack_b);
int				get_first(t_linked_list *list);
int				get_last(t_linked_list *list);
int				error(void);
int				min(t_linked_list *list);
int				max(t_linked_list *list);
int 			partition(t_linked_list *stack_a, t_linked_list *stack_b);
int				make_stack_to_idx(t_linked_list *list);
int				sort(int *arr, int size);
int rotate_stack_a(t_linked_list *stack_a, t_moving_counter *moving_counter);
int	is_sorted(t_linked_list *list);
int count_command_in_stack_a(int target, t_linked_list *stack_a, t_moving_counter *moving_counter);
int count_command_in_stack_b(int idx, t_linked_list *stack_b, t_moving_counter *moving_counter);
t_moving_counter	*find_minimum_greedy(t_linked_list *stack_a, t_linked_list *stack_b);
int	rotate(t_linked_list *stack_a, t_linked_list *stack_b, t_moving_counter *moving_counter);
int	reverse_rotate(t_linked_list *stack_a, t_linked_list *stack_b, t_moving_counter *moving_counter);
#endif