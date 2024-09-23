/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:39:51 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/23 23:28:59 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_back(t_stack **lst, t_stack *new_)
{
	t_stack	*start;

	if (*lst)
	{
		start = *lst;
		while (start->next)
			start = start->next;
		start->next = new_;
	}
	else
		*lst = new_;
}

void	ft_stackadd_front(t_stack **lst, t_stack *new_)
{
	if (lst)
	{
		new_->next = *lst;
		*lst = new_;
	}
}

t_stack	*ft_stacknew(int number)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (new)
	{
		new->number = number;
		new->above_median = 0;
		new->cheapest = 0;
		new->index = 0;
		new->push_cost = 0;
		new->target_node = NULL;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

int	ft_stacksize(t_stack *lst)
{
	t_stack	*start;
	int		i;

	i = 0;
	if (lst)
	{
		i++;
		start = lst->next;
		while (start)
		{
			start = start->next;
			i++;
		}
	}
	return (i);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	t_stack	*start;

	if (lst && lst->next)
	{
		start = lst->next;
		while (start->next)
		{
			start = start->next;
		}
		return (start);
	}
	return (lst);
}
