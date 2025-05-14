/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:38:36 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/29 18:40:29 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libs/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

# define SUCCESS 0
/* Internal process failure range 100 */
# define ERROR_MALLOC 101
/* External process failure range 200 | write stderr */
# define ERROR_INTEGER 201
# define ERROR_MAXINT 202
# define ERROR_DUPLICATED 203
# define ERROR_CMD 204
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
void	print_stack(t_stack *stack, char c);
int		ft_stack_sorted(t_stack *stack);
t_stack	*ft_stack_max(t_stack *stack);
t_stack	*ft_stack_min(t_stack *stack);

/* Free and Error*/

void	ft_error_handler(int signal, int *numbers, char **strs, int argc);
void	ft_free_argv(char **argv);
void	ft_free_stack(t_stack **lst);

/* Parser */

int		is_sorted(int *numbers, int size);
int		is_duplicated(int *numbers, int size);
int		is_integer(char *str);
int		ft_strslen(char **strs);
long	ft_atol(const char *str);

#endif //PUSH_SWAP_BONUS_H