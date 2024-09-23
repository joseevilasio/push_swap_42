/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:38:36 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/22 17:57:52 by joneves-         ###   ########.fr       */
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

typedef struct s_node
{
	int		number;
	int		index;
	int		cost;
	int		above_median;
	int		cheapest;
	t_list	*target_node;
}	t_node;

/* typedef struct s_stack_node //A container of data enclosed in {} braces. `s_` for struct
{
	int					nbr; //The number to sort
	int					index; //The number's position in the stack
	int					push_cost; //How many commands in total
	bool				above_median; //Used to calculate `push_cost`
	bool				cheapest; //The node that is the cheapest to do commands
	struct s_stack_node	*target_node; //The target node of a node in the opposite stack
	struct s_stack_node	*next; //A pointer to the next node
	struct s_stack_node	*prev; //A pointer to the previous node
}	t_stack_node; //The "shortened name", "t_stack_node". `t_` for type */

/* Operations */

/* 
sa (swap a): Troca os dois primeiros elementos no topo da pilha a.
Se houver apenas um ou nenhum elemento na pilha, nada acontece.

sb (swap b): Troca os dois primeiros elementos no topo da pilha b. 
Se houver apenas um ou nenhum elemento na pilha, nada acontece.

ss: Executa as operações sa e sb ao mesmo tempo, ou seja, troca os dois 
primeiros elementos das pilhas a e b simultaneamente. 
Se uma das pilhas tiver menos de dois elementos, nada acontece para aquela pilha.
*/

void	swap(t_list **stack_a, t_list **stack_b, char task);

/* 
pa (push a): Remove o primeiro elemento do topo da pilha b e o coloca no 
topo da pilha a. Se a pilha b estiver vazia, nada acontece.

pb (push b): Remove o primeiro elemento do topo da pilha a e o coloca no 
topo da pilha b. Se a pilha a estiver vazia, nada acontece.
*/

void	push(t_list **stack_a, t_list **stack_b, char task);

/*
ra (rotate a): Move todos os elementos da pilha a para cima em uma posição. 
O primeiro elemento se torna o último.

rb (rotate b): Move todos os elementos da pilha b para cima em uma posição. 
O primeiro elemento se torna o último.

rr: Executa as operações ra e rb ao mesmo tempo, ou seja, move os elementos 
das pilhas a e b para cima em uma posição simultaneamente.
O primeiro elemento de cada pilha se torna o último.
*/

void	rotate(t_list **stack_a, t_list **stack_b, char task);

/*
rra (reverse rotate a): Move todos os elementos da pilha a para baixo em 
uma posição. O último elemento se torna o primeiro.

rrb (reverse rotate b): Move todos os elementos da pilha b para baixo em
uma posição. O último elemento se torna o primeiro.

rrr: Executa as operações rra e rrb ao mesmo tempo, ou seja, move os
elementos das pilhas a e b para baixo em uma posição simultaneamente. 
O último elemento de cada pilha se torna o primeiro.
*/
void	rrotate(t_list **stack_a, t_list **stack_b, char task);

/* Utils */
long	ft_atol(const char *str);
int		is_integer(char *str);
int		is_duplicated(int *numbers, int size);
int		is_sorted(int *numbers, int size);

t_list	*build_stack(int *numbers, int size);
void	print_stack(t_list *stack, char c);
int		is_sorted_stack(t_list *stack);
int		get_nbr(t_list *stack); //nao usada
t_node	*get_node(t_list *stack);

t_list	*lst_max(t_list *stack);
t_list	*lst_min(t_list *stack);

void	stack_update(t_list *stack_a, t_list *stack_b, int task);
void	current_index(t_list *stack);
void	target_a(t_list *stack_a, t_list *stack_b);
void	target_b(t_list *stack_a, t_list *stack_b);
void	set_cheapest(t_list *stack);
void	cost_analysis_a(t_list *stack_a, t_list *stack_b);
t_list	*get_cheapest(t_list *stack) ;
void	prep_for_push(t_list **stack, t_list *top_node, char task);

void	ft_error_handler(int signal, int *numbers);
void	ft_free_argv(char **argv);

void	sort_small(t_list **stack_a, t_list **stack_b);
void	sort_big(t_list **stack_a, t_list **stack_b);

void	move_a_to_b(t_list **stack_a, t_list **stack_b);
void	rev_rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node);
void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node);
void	move_b_to_a(t_list **stack_a, t_list **stack_b);
void	min_on_top(t_list **stack_a);


#endif //PUSH_SWAP_H