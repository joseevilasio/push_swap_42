/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:20:42 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/28 21:48:54 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack_a, t_stack **stack_b, char task)
{
	t_stack	*first;
	t_stack	*second;
	int		i;

	i = 0;
	if (ft_stacksize(*stack_a) > 1 && (task == 'a' || task == 's'))
	{
		first = *stack_a;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack_a = second;
		i++;
	}
	if (ft_stacksize(*stack_b) > 1 && (task == 'b' || task == 's'))
	{
		first = *stack_b;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack_b = second;
		i++;
	}
	if (i > 0)
		ft_printf("s%c\n", task);
}

void	push(t_stack **stack_a, t_stack **stack_b, char task)
{
	t_stack	*head;

	if (task == 'a' && stack_b && *stack_b)
	{
		head = *stack_b;
		*stack_b = (*stack_b)->next;
		head->next = NULL;
		ft_stackadd_front(stack_a, head);
		ft_printf("p%c\n", task);
	}
	else if (task == 'b' && stack_a && *stack_a)
	{
		head = *stack_a;
		*stack_a = (*stack_a)->next;
		head->next = NULL;
		ft_stackadd_front(stack_b, head);
		ft_printf("p%c\n", task);
	}
}

void	rotate(t_stack **stack_a, t_stack **stack_b, char task)
{
	t_stack	*head;
	int		i;

	i = 0;
	if ((task == 'a' || task == 'r') && *stack_a && (*stack_a)->next)
	{
		head = *stack_a;
		*stack_a = (*stack_a)->next;
		head->next = NULL;
		ft_stackadd_back(stack_a, head);
		i++;
	}
	if ((task == 'b' || task == 'r') && *stack_b && (*stack_b)->next)
	{
		head = *stack_b;
		*stack_b = (*stack_b)->next;
		head->next = NULL;
		ft_stackadd_back(stack_b, head);
		i++;
	}
	if (i > 0)
		ft_printf("r%c\n", task);
}

void	rrotate(t_stack **stack_a, t_stack **stack_b, char task)
{
	t_stack	*tail;
	t_stack	*btail;
	int		i;

	i = 0;
	if ((task == 'a' || task == 'r') && *stack_a && (*stack_a)->next)
	{
		btail = *stack_a;
		while (btail->next->next)
			btail = btail->next;
		tail = btail->next;
		btail->next = NULL;
		ft_stackadd_front(stack_a, tail);
		i++;
	}
	if ((task == 'b' || task == 'r') && *stack_b && (*stack_b)->next)
	{
		btail = *stack_b;
		while (btail->next->next)
			btail = btail->next;
		tail = btail->next;
		btail->next = NULL;
		ft_stackadd_front(stack_b, tail);
		i++;
	}
	if (i > 0)
		ft_printf("rr%c\n", task);
}
