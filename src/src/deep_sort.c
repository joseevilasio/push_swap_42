/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:41:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/28 11:10:09 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	a;
	int	b;
	int	c;
	t_stack *current;

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
	//int x = 0;

	//print_stack(*stack_a, 'A');
	size = ft_stacksize(*stack_a);
	if (size-- > 3 && ft_stack_sorted(*stack_a) == -1)
		push(stack_a, stack_b, 'b');
	if (size-- > 3 && ft_stack_sorted(*stack_a) == -1)
		push(stack_a, stack_b, 'b');
 	while (size-- > 3 && ft_stack_sorted(*stack_a) == -1)
	{
		//x++;
		stack_update(*stack_a, *stack_b, 'a');
		//printf("Stack A\n [-- %d--] [%d] Number: %d|\nCost: %d|\nMedian: %d|\nCheapest: %d|\nNumber-Target: %d|\n",
		//x,(*stack_a)->index, (*stack_a)->number, (*stack_a)->push_cost, (*stack_a)->above_median, (*stack_a)->cheapest, (*stack_a)->target_node->number);
		move_a_to_b(stack_a, stack_b); //Move the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
		//if (x == 15)
		//	exit(1);
	}
	sort_small(stack_a, stack_b);
	while (*stack_b)
	{
		stack_update(*stack_a, *stack_b, 'b');
		move_b_to_a(stack_a, stack_b); //Move all `b` nodes back to a sorted stack `a`
	}
	current_index(*stack_a); //Refresh the current position of stack `a`
	min_on_top(stack_a); //Ensure smallest number is on top
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b) //Define a function that prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`, until there are three nodes left in `a`
{
	t_stack	*cheapest; //To store the pointer to the cheapest `a` node

	cheapest = get_cheapest(*stack_a); 
	if (cheapest->above_median && cheapest->target_node->above_median) //If both the cheapest `a` node and its target `b` node are above the median
		rotate_both(stack_a, stack_b, cheapest);
	else if (!cheapest->above_median && !cheapest->target_node->above_median) //If both the cheapest `a` node and its target `b` node are below the median
		rrotate_both(stack_a, stack_b, cheapest); //`rrotate_both` will execute if neither nodes are at the top
	prep_for_push(stack_a, cheapest, 'a'); //Ensure the cheapest nodes is at the top, ready for pushing
	prep_for_push(stack_b, cheapest->target_node, 'b'); //Ensure the target node is at the top, ready for pushing
	push(stack_a, stack_b, 'b');
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b) //Define a function that prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a` 
{
	prep_for_push(stack_a, (*stack_b)->target_node, 'a'); //Ensure `b`'s target `a` node is on top of the stack
	push(stack_a, stack_b, 'a'); 
}

void	min_on_top(t_stack **stack_a) //Define a function that moves the smallest number to the top
{
	while ((*stack_a)->number != ft_stack_min(*stack_a)->number) //As long as the smallest number is not at the top
	{
		if (ft_stack_min(*stack_a)->above_median) //Rotate or reverse rotate according to the position of the node on the median
			rotate(stack_a, NULL, 'a');
		else
			rrotate(stack_a, NULL, 'a');
	}
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest) //Define a function that rotates both the top `a` and `b` nodes to the bottom of their stacks, if it's the cheapest move
{
	while (*stack_b != cheapest->target_node
		&& *stack_a != cheapest) //As long as the current `b` node is not `a` cheapest node's target node, and the current top `a` node is not the top node
		rotate(stack_a, stack_b, 'r'); //Rotate both `a` and `b` nodes
	current_index(*stack_a);
	current_index(*stack_b);
}

void	rrotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest) //Define a function that rotates both the bottom `a` and `b` nodes to the top of their stacks, if it's the cheapest move
{
	while (*stack_b != cheapest->target_node && *stack_a != cheapest) //As long as the current `b` node is not `a` cheapest node's target node && and the current `a` node is not the cheapest
		rrotate(stack_a, stack_b, 'r'); //Reverse rotate both `a` and `b` nodes
	current_index(*stack_a); //Refresh current node positions
	current_index(*stack_b);
}