/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:32:17 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/29 15:31:18 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*build_stack(int *numbers, int size)
{
	t_stack	*stack_a;
	int		i;

	i = 0;
	stack_a = NULL;
	while (i < size)
	{
		ft_stackadd_back(&stack_a, ft_stacknew(numbers[i]));
		i++;
	}
	free(numbers);
	return (stack_a);
}

void	how_much(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_stacksize(stack_a);
	size_b = ft_stacksize(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!stack_a->above_median)
			stack_a->push_cost = size_a - stack_a->index;
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += size_b - stack_a->target_node->index;
		stack_a = stack_a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->cheapest = 1;
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	reordering(t_stack **stack, t_stack *top_node, char task)
{
	while (*stack != top_node)
	{
		if (task == 'a')
		{
			if (top_node->above_median == 1)
				rotate(stack, NULL, 'a');
			else
				rrotate(stack, NULL, 'a');
		}
		else if (task == 'b')
		{
			if (top_node->above_median == 1)
				rotate(NULL, stack, 'b');
			else
				rrotate(NULL, stack, 'b');
		}
	}
}
