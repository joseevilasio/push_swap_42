/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:32:17 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/28 11:12:04 by joneves-         ###   ########.fr       */
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

void	how_much(t_stack *stack_a, t_stack *stack_b) //Define a functio that analyses the cost of the `a` node along with it's target `b` node, which is the sum of the number of instructions for both the nodes to rotate to the top of their stacks
{
	int	size_a; //To store the sizegth of stack `a`
	int	size_b; //To store the sizegth of stack `b`

	size_a = ft_stacksize(stack_a);
	size_b = ft_stacksize(stack_b);
	//printf("Size a:%d Size b:%d \n", size_a, size_b);
	while (stack_a) //Loop through each node until the end of the stack is reached
	{
		stack_a->push_cost = stack_a->index; //Assign the current `a` node's push cost, its' index value
		if (!stack_a->above_median) //Check if the above_median data is false, meaning it is below median
			stack_a->push_cost = size_a - stack_a->index; //If so, update `a` node's push cost to the stack's sizegth - index
		if (stack_a->target_node->above_median) //Check if `a` node's target node `b` has a "true" above median attribute, meaning the target `b` node is above median
			stack_a->push_cost += stack_a->target_node->index; //If so, update `a` node's push cost, the sum of (its current index) + (its target `b` node's index)
		else //If `a` node is indeed above median and its target `b` node is below median
			stack_a->push_cost += size_b - stack_a->target_node->index; //Update `a` node's push cost, the sum of (its current index) + (`b` stack's sizegth - its target `b` node's index)
		stack_a = stack_a->next; //Move to the next `a` node for its cost analysis
	}
}

void	set_cheapest(t_stack *stack) //Define a function that sets a node's `cheapest` attribute as `true` or `false`
{
	long	cheapest_value; //To store the value of the cheapest node so far
	t_stack	*cheapest; //To store a pointer to the cheapest node so far

	if (!stack) //Check for an empty stack
		return ;
	cheapest_value = LONG_MAX; //Assign the biggest `long` as the cheapest value so far
	while (stack) //Loop through every node until the end of the stack is reached, and we find the cheapest node
	{
		if (stack->push_cost < cheapest_value) //Check if the current node's push cost is cheaper than the cheapest value so far
		{
			cheapest_value = stack->push_cost; //If so, update the cheapest value to the current node's push cost
			cheapest = stack; //Assign the current node as the cheapest node so far
		}
		stack = stack->next; //Move to the next node for comparison
	}
	cheapest->cheapest = 1; //After iterating through the stack, if no cheaper node is found than the current, then set the cheapest node's `cheapest` attribut to `true` in the data structure
}


t_stack	*get_cheapest(t_stack *stack) //Define a function that searches for the cheapest node, that is set by bool
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

void	prep_for_push(t_stack **stack, t_stack *top_node, char task) //Define a function that moves the required node to the top of the stack
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (task == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median == 1)
				rotate(stack, NULL, 'a');
			else
				rrotate(stack, NULL, 'a');
		}
		else if (task == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median == 1)
				rotate(NULL, stack, 'b');
			else
				rrotate(NULL, stack, 'b');
		}	
	}
}
