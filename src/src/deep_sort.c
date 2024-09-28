/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:41:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/28 21:45:08 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int		a;
	int		b;
	int		c;
	t_stack	*current;

	current = *stack_a;
	a = current->number;
	b = current->next->number;
	c = current->next->next->number;
	if (a > b && a > c)
		rotate(stack_a, stack_b, 'a');
	current = *stack_a;
	a = current->number;
	b = current->next->number;
	c = current->next->next->number;
	if (a < b && b > c)
		rrotate(stack_a, stack_b, 'a');
	current = *stack_a;
	a = current->number;
	b = current->next->number;
	c = current->next->next->number;
	if (a > b)
		swap(stack_a, stack_b, 'a');
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stacksize(*stack_a);
	if (size-- > 3 && ft_stack_sorted(*stack_a) == -1)
		push(stack_a, stack_b, 'b');
	if (size-- > 3 && ft_stack_sorted(*stack_a) == -1)
		push(stack_a, stack_b, 'b');
	while (size-- > 3 && ft_stack_sorted(*stack_a) == -1)
	{
		stack_update(*stack_a, *stack_b, 'a');
		move_a_to_b(stack_a, stack_b);
	}
	sort_small(stack_a, stack_b);
	while (*stack_b)
	{
		stack_update(*stack_a, *stack_b, 'b');
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_on_top(stack_a);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
		rrotate_both(stack_a, stack_b, cheapest);
	prep_for_push(stack_a, cheapest, 'a');
	prep_for_push(stack_b, cheapest->target_node, 'b');
	push(stack_a, stack_b, 'b');
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	push(stack_a, stack_b, 'a');
}

void	min_on_top(t_stack **stack_a)
{
	while ((*stack_a)->number != ft_stack_min(*stack_a)->number)
	{
		if (ft_stack_min(*stack_a)->above_median)
			rotate(stack_a, NULL, 'a');
		else
			rrotate(stack_a, NULL, 'a');
	}
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_b != cheapest->target_node
		&& *stack_a != cheapest)
		rotate(stack_a, stack_b, 'r');
	current_index(*stack_a);
	current_index(*stack_b);
}

void	rrotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_b != cheapest->target_node && *stack_a != cheapest)
		rrotate(stack_a, stack_b, 'r');
	current_index(*stack_a);
	current_index(*stack_b);
}
