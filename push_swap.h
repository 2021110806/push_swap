/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:59:56 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/29 08:49:35 by minjeon2         ###   ########.fr       */
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

t_linked_list		*make_new_list(void);
t_node				*make_new_node(int item);
int					add_first(t_linked_list *list, t_node *new_node);
int					add_last(t_linked_list *list, t_node *new_node);
int					print_all(t_linked_list *list);
int					delete_last(t_linked_list *list);
int					delete_first(t_linked_list *list);
int					pa(t_linked_list *stack_a, t_linked_list *stack_b);
int					pb(t_linked_list *stack_a, t_linked_list *stack_b);
int					ra(t_linked_list *stack_a, int is_rr);
int					rb(t_linked_list *stack_b, int is_rr);
int					rr(t_linked_list *stack_a, t_linked_list *stack_b);
int					rrb(t_linked_list *stack_b, int is_rrr);
int					rra(t_linked_list *stack_a, int is_rrr);
int					rrr(t_linked_list *stack_a, t_linked_list *stack_b);
int					sa(t_linked_list *stack_a);
int					sb(t_linked_list *stack_b);
int					ss(t_linked_list *stack_a, t_linked_list *stack_b);
int					get_first(t_linked_list *list);
int					get_last(t_linked_list *list);
int					error(void);
int					min(t_linked_list *list);
int					max(t_linked_list *list);
void				partition(t_linked_list *stack_a, t_linked_list *stack_b);
void				make_stack_to_idx(t_linked_list *list);
void				count_command_in_stack_a(int target, \
					t_linked_list *stack_a, t_moving_counter *moving_counter);
void				count_command_in_stack_b(int idx, t_linked_list *stack_b, \
					t_moving_counter *moving_counter);
int					move_min_value_to_top(t_linked_list *stack_a);
void				find_minimum_greedy(t_linked_list *stack_a, \
t_linked_list *stack_b, t_moving_counter *min_moving);
void				rotate(t_linked_list *stack_a, t_linked_list *stack_b, \
					t_moving_counter *moving_counter);
void				reverse_rotate(t_linked_list *stack_a, \
					t_linked_list *stack_b, t_moving_counter *moving_counter);
int					abs_(int inp);
int					is_valid_input(char **argv, int argc, \
					t_linked_list *stack_a);
int					find_distance_to_min_value(t_linked_list *stack_a);
void				match_idx_witch_contents(t_linked_list	*list, int *dct);
void				count_command_when_target_is_min( \
					t_moving_counter *moving_counter, t_linked_list *stack_a);
void				count_command_when_target_is_max( \
					t_moving_counter *moving_counter, t_linked_list *stack_a);
int					count_command_when_target_is_top( \
					t_moving_counter *moving_counter, t_linked_list *stack_a);
void				count_command_when_general_case(t_linked_list *stack_a, \
					int target, t_moving_counter *moving_counter);
void				update_moving_counter(\
t_moving_counter *min_moving, t_moving_counter *moving_counter);
int					is_sorted(t_linked_list *list);
void				sort(int *arr, int size);
void				match_idx_with_contents(t_linked_list	*list, int *dct);
int					sort_when_size_is_two(t_linked_list *stack_a);
int					sort_when_size_is_three(\
t_linked_list *stack_a, t_linked_list *stack_b);
int					sort_when_size_is_four(\
t_linked_list *stack_a, t_linked_list *stack_b);
int					sort_when_size_is_five(\
t_linked_list *stack_a, t_linked_list *stack_b);
int					sort_when_input_is_few(\
t_linked_list *stack_a, t_linked_list *stack_b);
void				rotate_stack(t_linked_list *stack_a, \
t_linked_list *stack_b, t_moving_counter *moving_counter);
int					is_duplicate(t_linked_list *stack_a, int target);
#endif