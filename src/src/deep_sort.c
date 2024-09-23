/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:41:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/22 18:44:34 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_list **stack_a, t_list **stack_b)
{
	int	a;
	int	b;
	int	c;
	t_list *current;

	current = *stack_a;
	a = get_nbr(current);
	b = get_nbr(current->next);
	c = get_nbr(current->next->next);
	if (a > b && a > c)
		rotate(stack_a, stack_b, 'a');
	current = *stack_a;
	a = get_nbr(current);
	b = get_nbr(current->next);
	c = get_nbr(current->next->next);
	if (a < b && b > c)
		rrotate(stack_a, stack_b, 'a');
	current = *stack_a;
	a = get_nbr(current);
	b = get_nbr(current->next);
	c = get_nbr(current->next->next);
	if (a > b)
		swap(stack_a, stack_b, 'a');
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size-- > 3 && is_sorted_stack(*stack_a) == -1)
		push(stack_a, stack_b, 'b');
	if (size-- > 3 && is_sorted_stack(*stack_a) == -1)
		push(stack_a, stack_b, 'b');

 	while (size-- > 3 && is_sorted_stack(*stack_a) == -1)
	{
		stack_update(*stack_a, *stack_b, 'a');
		move_a_to_b(stack_a, stack_a); //Move the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
	}
	sort_small(stack_a, stack_b);
	print_stack(*stack_a, 'A');
	print_stack(*stack_b, 'B');
	while (*stack_b)
	{
		stack_update(*stack_a, *stack_b, 'b');
		print_stack(*stack_a, 'A');
		print_stack(*stack_b, 'B');
		move_b_to_a(stack_a, stack_b); //Move all `b` nodes back to a sorted stack `a`
	}
	current_index(*stack_a); //Refresh the current position of stack `a`
	min_on_top(stack_a); //Ensure smallest number is on top
}

void	move_a_to_b(t_list **stack_a, t_list **stack_b) //Define a function that prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`, until there are three nodes left in `a`
{
	t_list	*cheapest_node; //To store the pointer to the cheapest `a` node

	cheapest_node = get_cheapest(*stack_a); 
	if (get_node(cheapest_node)->above_median 
		&& get_node(get_node(cheapest_node)->target_node)->above_median) //If both the cheapest `a` node and its target `b` node are above the median
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!get_node(cheapest_node)->above_median
		&& !(get_node(get_node(cheapest_node)->target_node)->above_median)) //If both the cheapest `a` node and its target `b` node are below the median
		rev_rotate_both(stack_a, stack_b, cheapest_node); //`rev_rotate_both` will execute if neither nodes are at the top
	prep_for_push(stack_a, cheapest_node, 'a'); //Ensure the cheapest nodes is at the top, ready for pushing
	prep_for_push(stack_b, cheapest_node, 'b'); //Ensure the target node is at the top, ready for pushing
	push(stack_a, stack_b, 'b');
}

void	move_b_to_a(t_list **stack_a, t_list **stack_b) //Define a function that prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a` 
{
	prep_for_push(stack_a, *stack_b, 'a'); //Ensure `b`'s target `a` node is on top of the stack
	push(stack_a, stack_b, 'a'); 
}

void	min_on_top(t_list **stack_a) //Define a function that moves the smallest number to the top
{
	while (get_node(*stack_a)->number != get_node(lst_min(*stack_a))->number) //As long as the smallest number is not at the top
	{
		if (get_node(lst_min(*stack_a))->above_median) //Rotate or reverse rotate according to the position of the node on the median
			rotate(stack_a, NULL, 'a');
		else
			rrotate(stack_a, NULL, 'a');
	}
}

void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node) //Define a function that rotates both the top `a` and `b` nodes to the bottom of their stacks, if it's the cheapest move
{
	while (*stack_b != get_node(cheapest_node)->target_node
		&& *stack_a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node, and the current top `a` node is not the top node
		rotate(stack_a, stack_b, 'r'); //Rotate both `a` and `b` nodes
	current_index(*stack_a);
	current_index(*stack_b);
}

void	rev_rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node) //Define a function that rotates both the bottom `a` and `b` nodes to the top of their stacks, if it's the cheapest move
{
	while (*stack_b != get_node(cheapest_node)->target_node
		&& *stack_a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node && and the current `a` node is not the cheapest
		rrotate(stack_a, stack_b, 'r'); //Reverse rotate both `a` and `b` nodes
	current_index(*stack_a); //Refresh current node positions
	current_index(*stack_b);
}