/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:41:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/19 23:02:20 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallsmall(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;
	t_list *current;

	current = *stack_a;
	a = *((int *) current->content);
	b = *((int *) current->next->content);
	c = *((int *) current->next->next->content);
	if (a > b && a > c)
		rotate(stack_a, NULL, 'a');
	current = *stack_a;
	a = *((int *) current->content);
	b = *((int *) current->next->content);
	c = *((int *) current->next->next->content);
	if (a < b && b > c)
		rrotate(stack_a, NULL, 'a');
	current = *stack_a;
	a = *((int *) current->content);
	b = *((int *) current->next->content);
	c = *((int *) current->next->next->content);
	if (a > b)
		swap(stack_a, NULL, 'a');
}
