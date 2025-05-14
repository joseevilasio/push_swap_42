/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:44:55 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/30 20:51:32 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_update(t_stack *stack_a, t_stack *stack_b, int task)
{
	current_index(stack_a);
	current_index(stack_b);
	if (task == 'a')
	{
		target_a(stack_a, stack_b);
		how_much(stack_a, stack_b);
		set_cheapest(stack_a);
	}
	if (task == 'b')
		target_b(stack_a, stack_b);
}

void	current_index(t_stack *stack)
{
	int		i;
	int		median;

	i = 0;
	median = ft_stacksize(stack) / 2;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*curr_b;
	t_stack	*target_node;
	long	match;

	while (stack_a)
	{
		match = LONG_MIN;
		curr_b = stack_b;
		while (curr_b)
		{
			if (curr_b->number < stack_a->number && curr_b->number > match)
			{
				match = curr_b->number;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (match == LONG_MIN)
			stack_a->target_node = ft_stack_max(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

void	target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*curr_a;
	t_stack	*target_node;
	long	match;

	while (stack_b)
	{
		match = LONG_MAX;
		curr_a = stack_a;
		while (curr_a)
		{
			if ((curr_a)->number > (stack_b)->number
				&& (curr_a)->number < match)
			{
				match = (curr_a)->number;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (match == LONG_MAX)
			stack_b->target_node = ft_stack_min(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}
