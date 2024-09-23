/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:03:59 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/22 18:09:51 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (sign * number);
}

int	is_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	is_duplicated(int *numbers, int size)
{
	int	i;
	int	j;
	int	ref;

	i = 0;
	while (i < size)
	{
		ref = numbers[i];
		j = i + 1;
		while (j < size)
		{
			if (ref == numbers[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(int *numbers, int size)
{
	int	i;
	int	j;
	int	ref;

	i = 0;
	while (i < size)
	{
		ref = numbers[i];
		j = i + 1;
		while (j < size)
		{
			if (ref > numbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (-1);
}

t_list	*build_stack(int *numbers, int size)
{
	t_list	*stack_a;
	t_node	*node;
	int		i;

	i = 0;
	stack_a = NULL;
	while (i < size)
	{
		node = (t_node *) malloc(sizeof(t_node));
		if (!node)
		{
			ft_lstclear(&stack_a, free);
			ft_error_handler(ERROR_MALLOC, numbers);
		}
		node->number = numbers[i];
		node->index = 0;
		node->above_median = 0;
		node->cheapest= 0;
		node->cost = 0;
		node->target_node = NULL;
		ft_lstadd_back(&stack_a, ft_lstnew(node));
		i++;
	}
	return (stack_a);
}

void	print_stack(t_list *stack, char c)
{
	t_node *node;

	ft_printf(" -- Stack %c -- \n", c);
	if (!stack)
		ft_printf("empty\n");
	while (stack != NULL)
	{
		node = stack->content;
		ft_printf("[%d] ", node->index);
		ft_printf("%d \n", node->number);
		// if (get_node(node->target_node))
		// 	ft_printf("%d", get_node(node->target_node)->number);
		stack = stack->next;
	}
}

int	is_sorted_stack(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (get_node(stack)->number > get_node(stack->next)->number)
			return (-1);
		stack = stack->next;
	}
	return (0);
}

int	get_nbr(t_list *stack)
{
	return (*((int *) stack->content));
}

t_node	*get_node(t_list *stack)
{
	return (((t_node *) stack->content));
}

t_list	*lst_max(t_list *stack)
{
	int		max;
	t_list	*max_node;

	if (!stack)
		return (NULL);
	max = get_node(stack)->number;
	max_node = stack;
	while (stack)
	{
		if (get_node(stack)->number > max)
		{
			max = get_node(stack)->number;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_list	*lst_min(t_list *stack)
{
	int		min;
	t_list	*min_node;

	if (!stack)
		return (NULL);
	min = get_node(stack)->number;
	min_node = stack;
	while (stack)
	{
		if (get_node(stack)->number < min)
		{
			min =  get_node(stack)->number;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
