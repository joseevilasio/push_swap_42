/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:20:42 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/17 20:59:36 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack_a, t_list **stack_b, char task)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(*stack_a) > 1)
	{
		first = *stack_a;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack_a = second;
		if (task)
			ft_printf("s%c\n", task);
	}
	if (stack_b && ft_lstsize(*stack_b) > 1)
		swap(stack_b, NULL, 0);
}

void	push(t_list **stack_a, t_list **stack_b, char task)
{
	t_list	*head;

	if (task == 'a' && stack_b && *stack_b && ft_lstsize(*stack_b) > 0)
	{
		head = *stack_b;
		*stack_b = (*stack_b)->next;
		head->next = NULL;
		ft_lstadd_front(stack_a, head);
		ft_printf("p%c\n", task);
	}
	if (task == 'b' && stack_a && *stack_a && ft_lstsize(*stack_a) > 0)
	{
		head = *stack_a;
		*stack_a = (*stack_a)->next;
		head->next = NULL;
		ft_lstadd_front(stack_b, head);
		ft_printf("p%c\n", task);
	}
}

void	rotate(t_list **stack_a, t_list **stack_b, char task)
{
	t_list	*head;

	if ((task == 'a' || task == 'r') && stack_a && *stack_a
		&& ft_lstsize(*stack_a) > 0)
	{
		head = *stack_a;
		*stack_a = (*stack_a)->next;
		head->next = NULL;
		ft_lstadd_back(stack_a, head);
	}
	if ((task == 'b' || task == 'r') && stack_b && *stack_b
		&& ft_lstsize(*stack_b) > 0)
	{
		head = *stack_b;
		*stack_b = (*stack_b)->next;
		head->next = NULL;
		ft_lstadd_back(stack_b, head);
	}
	ft_printf("r%c\n", task);
}

void	rrotate(t_list **stack_a, t_list **stack_b, char task)
{
	t_list	*tail;
	t_list	*btail;

	if ((task == 'a' || task == 'r') && stack_a && *stack_a
		&& ft_lstsize(*stack_a) > 0)
	{
		btail = *stack_a;
		while (btail->next->next)
			btail = btail->next;
		tail = btail->next;
		btail->next = NULL;
		ft_lstadd_front(stack_a, tail);
	}
	if ((task == 'b' || task == 'r') && stack_b && *stack_b
		&& ft_lstsize(*stack_b) > 0)
	{
		btail = *stack_b;
		while (btail->next->next)
			btail = btail->next;
		tail = btail->next;
		btail->next = NULL;
		ft_lstadd_front(stack_b, tail);
	}
	ft_printf("rr%c\n", task);
}
