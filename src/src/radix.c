/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:41:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/19 13:24:12 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;
	int		*num_ptr;

	head = *stack;
	num_ptr = (int *) head->content;
	max = num_ptr[1];
	max_bits = 0;
	while (head)
	{
		num_ptr = (int *) head->content;
		if (num_ptr[1] > max)
			max = num_ptr[1];
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		i;
	int		j;
	int		size;
	int		max_bits;
	int		*num_ptr;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			current = *stack_a;
			num_ptr = (int *) current->content;
			if (((num_ptr[1] >> i) & 1) == 1)
				rotate(stack_a, NULL, 'a');
			else
				push(stack_a, stack_b, 'b');
		}
		while (ft_lstsize(*stack_b) != 0)
			push(stack_a, stack_b, 'a');
		i++;
	}
}

void	quicksort_pilhas(t_list **stack_a, t_list **stack_b)
{

    int pivot;
    int count = 0;
	int	size;

	int	*num_ptr;
	num_ptr = (int *) (*stack_a)->content;

	size = ft_lstsize(*stack_a);

    if (size <= 1)
        return;

    // Pegando o último elemento como pivô (você pode mudar a estratégia de seleção do pivô)
    pivot = *num_ptr;

    // Particionamento: movendo os elementos menores para stack_b
    while (size-- > 0) {
		num_ptr = (int *) (*stack_a)->content;
        int current_value = *num_ptr;
        
        if (current_value <= pivot) {
            // Move para o final da pilha A (ra)
            rotate(stack_a, NULL, 'a');
        } else {
            // Move o elemento para a pilha B (pb)
            push(stack_a, stack_b, 'b');
            count++;
        }
    }

    // Chamada recursiva para as duas partições (elementos menores e maiores que o pivô)
    quicksort_pilhas(stack_a, stack_b);  // Ordena os elementos menores
    quicksort_pilhas(stack_b, stack_a);  // Ordena os elementos maiores

    // Move os elementos de volta da pilha B para a pilha A
    while (count-- > 0) {
        push(stack_a, stack_b, 'a');
    }
}

/* void	small(t_list **stack_a, t_list **stack_b)
{
	int	pivot_a;
	t_list *current;
	// int	pivot_b;
	// int i = 0;

	pivot_a = *((int *) (*stack_a)->content);
	// int size_a = ft_lstsize(*stack_a);
	rotate(stack_a, stack_b, 'a');
	current = *stack_a;
	// pivot_b = *((int *) (*stack_b)->content);
	while (current)
	{
		ft_printf(" %d > %d\n", *((int *) current->content), pivot_a);
		if (*((int *) current->content) > pivot_a)
		{
			
			push(stack_a, stack_b, 'b');
		}
		// else
		// 	rotate(stack_a, stack_b, 'a');
		current = *stack_a;
	}	
} */

void	smallsmall(t_list **stack_a, t_list **stack_b)
{
	t_list *current;
	int	a;
	int	b;
	int	c;

	push(stack_a, stack_b, 'b');
	current = *stack_a;
	a = *((int *) current->content);
	b = *((int *) current->next->content);
	if (a > b)
		swap(stack_a, stack_b, 'a');
	push(stack_a, stack_b, 'a');
	current = *stack_a;
	a = *((int *) current->content);
	b = *((int *) current->next->content);
	c = *((int *) ft_lstlast(*stack_a));
	if (a < b)
		return;
	if (a > b && a > c)
		rotate(stack_a, stack_b, 'a');
	else
		swap(stack_a, stack_b, 'a');
}

