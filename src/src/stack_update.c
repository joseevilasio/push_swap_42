/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:44:55 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/22 19:13:35 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_update(t_list *stack_a, t_list *stack_b, int task)
{
	current_index(stack_a);
	current_index(stack_b);
	if (task == 'a')
	{
		ft_printf("running task a \n");
		target_a(stack_a, stack_b);
		cost_analysis_a(stack_a, stack_b);
		set_cheapest(stack_a);
	}
	if (task == 'b')
	{		
		ft_printf("running task b \n");
		target_b(stack_a, stack_b);
	}
}

void	current_index(t_list *stack) 
{
	int		i;
	int		median;

	i = 0;
	median = ft_lstsize(stack) / 2;
	if (!stack)
		return;
	while (stack)
	{
		((t_node *) stack->content)->index = i;
		if (i <= median)
			((t_node *) stack->content)->above_median = 1;
		else
			((t_node *) stack->content)->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	target_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*curr_b;
	t_list	*target_node;
	long	match;

	while (stack_a)
	{
		match = LONG_MIN;
		curr_b = stack_b;
		while (curr_b)
		{
			if (get_node(curr_b)->number < get_node(stack_a)->number
				&& get_node(curr_b)->number > match)
			{
				match = get_node(curr_b)->number;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (match == LONG_MIN)
			((t_node *) stack_a->content)->target_node = lst_max(stack_b);
		else
			((t_node *) stack_a->content)->target_node  = target_node;
		stack_a = stack_a->next;
	}
}

void	target_b(t_list *stack_a, t_list *stack_b)
{
	t_list	*curr_a;
	t_list	*target_node;
	long	match;

	while (stack_b)
	{
		match = LONG_MAX;
		curr_a = stack_a;
		while (curr_a)
		{
			if (get_node(curr_a)->number > get_node(stack_b)->number
				&& get_node(curr_a)->number < match)
			{
				match = get_node(curr_a)->number;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (match == LONG_MAX)
			((t_node *) stack_b->content)->target_node = lst_min(stack_a);
		else
			((t_node *) stack_b->content)->target_node  = target_node;
		stack_b = stack_b->next;
	}
}

void	cost_analysis_a(t_list *stack_a, t_list *stack_b) //Define a functio that analyses the cost of the `a` node along with it's target `b` node, which is the sum of the number of instructions for both the nodes to rotate to the top of their stacks
{
	int	size_a; //To store the sizegth of stack `a`
	int	size_b; //To store the sizegth of stack `b`

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	while (stack_a) //Loop through each node until the end of the stack is reached
	{
		((t_node *) stack_a->content)->cost = get_node(stack_a)->index; //Assign the current `a` node's push cost, its' index value
		if (!get_node(stack_a)->above_median) //Check if the above_median data is false, meaning it is below median
			((t_node *) stack_a->content)->cost = size_a - get_node(stack_a)->index; //If so, update `a` node's push cost to the stack's sizegth - index
		if (!get_node(get_node(stack_a)->target_node)->above_median) //Check if `a` node's target node `b` has a "true" above median attribute, meaning the target `b` node is above median
			((t_node *) stack_a->content)->cost += get_node(get_node(stack_a)->target_node)->index; //If so, update `a` node's push cost, the sum of (its current index) + (its target `b` node's index)
		else //If `a` node is indeed above median and its target `b` node is below median
			((t_node *) stack_a->content)->cost += size_b - get_node(get_node(stack_a)->target_node)->index; //Update `a` node's push cost, the sum of (its current index) + (`b` stack's sizegth - its target `b` node's index)
		printf("cost %d |\n", ((t_node *) stack_a->content)->cost);
		stack_a = stack_a->next; //Move to the next `a` node for its cost analysis
	}
}

void	set_cheapest(t_list *stack) //Define a function that sets a node's `cheapest` attribute as `true` or `false`
{
	long			cheapest_value; //To store the value of the cheapest node so far
	t_list	*cheapest_node; //To store a pointer to the cheapest node so far

	if (!stack) //Check for an empty stack
		return ;
	cheapest_value = LONG_MAX; //Assign the biggest `long` as the cheapest value so far
	while (stack) //Loop through every node until the end of the stack is reached, and we find the cheapest node
	{
		if (get_node(stack)->cost < cheapest_value) //Check if the current node's push cost is cheaper than the cheapest value so far
		{
			cheapest_value = get_node(stack)->cost; //If so, update the cheapest value to the current node's push cost
			cheapest_node = stack; //Assign the current node as the cheapest node so far
		}
		stack = stack->next; //Move to the next node for comparison
	}
	((t_node *) cheapest_node->content)->cheapest = 1; //After iterating through the stack, if no cheaper node is found than the current, then set the cheapest node's `cheapest` attribut to `true` in the data structure
}


t_list	*get_cheapest(t_list *stack) //Define a function that searches for the cheapest node, that is set by bool
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (get_node(stack)->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_list **stack, t_list *top_node, char task) //Define a function that moves the required node to the top of the stack
{
	//printf("%c | %d -->%d\n",task, get_node(*stack)->number, get_node(top_node)->number);
	if (top_node)
		top_node = get_node(top_node)->target_node;
	else
		top_node = NULL;
	int median;
	median = 0;
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (top_node)
			median = get_node(top_node)->above_median;
		if (task == 'a') //If not, and it is stack `a`, execute the following
		{
			if (median == 1)
				rotate(stack, NULL, 'a');
			else
				rrotate(stack, NULL, 'a');
		}
		else if (task == 'b') //If not, and it is stack `b`, execute the following
		{
			if (median == 1)
				rotate(NULL, stack, 'b');
			else
				rrotate(NULL, stack, 'b');
		}	
	}
}