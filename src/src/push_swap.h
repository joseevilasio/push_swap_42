/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:38:36 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/23 22:49:01 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

# define SUCCESS 0
/* Internal process failure range 100 */
# define ERROR_MALLOC 101
/* External process failure range 200 | ft_printf() */
# define ERROR_INTEGER 201
# define ERROR_MAXINT 202
# define ERROR_DUPLICATED 203
/* External process failure range 300 | without ft_printf() */
# define ERROR_SORTED 301
# define ERROR_ARGS 302

typedef struct s_stack
{
	int				number;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	//struct s_stack_node	*prev; //A pointer to the previous node
}	t_stack;

/* Operations */

/* sa (swap a) | sb (swap b) | ss */
void	swap(t_stack **stack_a, t_stack **stack_b, char task);
/* pa (push a) | pb (push b) */
void	push(t_stack **stack_a, t_stack **stack_b, char task);
/* ra (rotate a) | rb (rotate b) | rr: */
void	rotate(t_stack **stack_a, t_stack **stack_b, char task);
/* rra (reverse rotate a) | rrb (reverse rotate b) | rrr */
void	rrotate(t_stack **stack_a, t_stack **stack_b, char task);

/* Stack manipulation */

void	ft_stackadd_back(t_stack **lst, t_stack *new_);
void	ft_stackadd_front(t_stack **lst, t_stack *new_);
int		ft_stacksize(t_stack *lst);
t_stack	*ft_stacknew(int number);
t_stack	*ft_stacklast(t_stack *lst);

/* Stack Factory */

t_stack	*build_stack(int *numbers, int size);
void	set_cheapest(t_stack *stack);
void	cost_analysis_a(t_stack *stack_a, t_stack *stack_b);
t_stack	*get_cheapest(t_stack *stack) ;
void	prep_for_push(t_stack **stack, t_stack *top_node, char task);

/* Stack Uptade */

void	stack_update(t_stack *stack_a, t_stack *stack_b, int task);
void	current_index(t_stack *stack);
void	target_a(t_stack *stack_a, t_stack *stack_b);
void	target_b(t_stack *stack_a, t_stack *stack_b);

/* Utils */

void	print_stack(t_stack *stack, char c);
int		ft_stack_sorted(t_stack *stack);
t_stack	*ft_stack_max(t_stack *stack);
t_stack	*ft_stack_min(t_stack *stack);

/* Free and Error*/

void	ft_error_handler(int signal, int *numbers);
void	ft_free_argv(char **argv);

void	sort_small(t_stack **stack_a, t_stack **stack_b);
void	sort_big(t_stack **stack_a, t_stack **stack_b);

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);
void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	min_on_top(t_stack **stack_a);

/* Parser */

int	*get_numbers(char **argv, int size);
int	is_sorted(int *numbers, int size);

#endif //PUSH_SWAP_H