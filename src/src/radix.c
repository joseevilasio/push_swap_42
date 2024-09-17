/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:41:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/17 21:06:49 by joneves-         ###   ########.fr       */
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
