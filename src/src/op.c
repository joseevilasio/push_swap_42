/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:25:39 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/15 19:08:33 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
sa (swap a): Troca os dois primeiros elementos no topo da pilha a.
Se houver apenas um ou nenhum elemento na pilha, nada acontece.

sb (swap b): Troca os dois primeiros elementos no topo da pilha b. 
Se houver apenas um ou nenhum elemento na pilha, nada acontece.

ss: Executa as operações sa e sb ao mesmo tempo, ou seja, troca os dois 
primeiros elementos das pilhas a e b simultaneamente. 
Se uma das pilhas tiver menos de dois elementos, nada acontece para aquela pilha.
*/

void	swap(int *stack_a, int *stack_b, char task, int len_a, int len_b)
{
	int	swap_;

	swap_ = stack_a[0];
	if (len_a >= 2)
	{
		stack_a[0] = stack_a[1];
		stack_a[1] = swap_;
		if (task)
			ft_printf("s%c\n", task);
	}
	if (stack_b && len_b >= 2)
		swap(stack_b, NULL, 0, len_b, 0);
}

/* 
pa (push a): Remove o primeiro elemento do topo da pilha b e o coloca no 
topo da pilha a. Se a pilha b estiver vazia, nada acontece.

pb (push b): Remove o primeiro elemento do topo da pilha a e o coloca no 
topo da pilha b. Se a pilha a estiver vazia, nada acontece.
*/

