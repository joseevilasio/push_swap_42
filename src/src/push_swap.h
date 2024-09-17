/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:38:36 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/17 20:49:19 by joneves-         ###   ########.fr       */
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

void	ft_error_handler(int signal, int *numbers);

void	radix(t_list **stack_a, t_list **stack_b);

#endif //PUSH_SWAP_H