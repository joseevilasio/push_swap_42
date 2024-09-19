/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:03:59 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/19 19:49:51 by joneves-         ###   ########.fr       */
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
	int		i;
	int		*num_ptr;

	i = 0;
	stack_a = NULL;
	while (i < size)
	{
		num_ptr = malloc(sizeof(int));
		if (!num_ptr)
		{
			ft_lstclear(&stack_a, free);
			ft_error_handler(ERROR_MALLOC, numbers);
		}
		*num_ptr = numbers[i];
		ft_lstadd_back(&stack_a, ft_lstnew(num_ptr));
		i++;
	}
	return (stack_a);
}

/* t_list	*build_stack(int *numbers, int size)
{
	t_list	*stack_a;
	int		i;
	int		*num_ptr;

	i = 0;
	stack_a = NULL;
	while (i < size)
	{
		num_ptr = malloc(2 * sizeof(int));
		if (!num_ptr)
		{
			ft_lstclear(&stack_a, free);
			ft_error_handler(ERROR_MALLOC, numbers);
		}
		num_ptr[0] = numbers[i];
		num_ptr[1] = i;
		ft_lstadd_back(&stack_a, ft_lstnew(num_ptr));
		i++;
	}
	return (stack_a);
} */

void	print_stack(t_list *stack, char c)
{
	ft_printf(" -- Stack %c -- \n", c);
	while (stack != NULL)
	{
		ft_printf("%d\n", *((int *) stack->content));
		stack = stack->next;
	}
}

/* void	print_stack(t_list *stack, char c)
{
	int	*num_ptr;

	ft_printf(" -- Stack %c -- \n", c);
	while (stack != NULL)
	{
		num_ptr = (int *) stack->content;
		ft_printf("[%d] -> %d\n", num_ptr[1], num_ptr[0]);
		stack = stack->next;
	}
} */