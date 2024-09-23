/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:03:59 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/23 20:40:11 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, char c)
{
	ft_printf(" -- Stack %c -- \n", c);
	if (!stack)
		ft_printf("empty\n");
	while (stack)
	{
		ft_printf("[%d] ", stack->index);
		ft_printf("%d \n", stack->number);
		stack = stack->next;
	}
}

int	ft_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (-1);
		stack = stack->next;
	}
	return (0);
}

t_stack	*ft_stack_max(t_stack *stack)
{
	int		max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = stack->number;
	max_node = stack;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*ft_stack_min(t_stack *stack)
{
	int		min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = (stack)->number;
	min_node = stack;
	while (stack)
	{
		if (stack->number < min)
		{
			min = stack->number;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
