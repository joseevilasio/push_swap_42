/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:35:25 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/23 22:47:12 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
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

static int	is_integer(char *str)
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

static int	is_duplicated(int *numbers, int size)
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

int	*get_numbers(char **argv, int size)
{
	int		i;
	int		j;
	long	number;
	int		*numbers;

	i = 0;
	j = 0;
	numbers = (int *) malloc(size * sizeof(int));
	if (!numbers)
		ft_error_handler(ERROR_MALLOC, numbers);
	while (i < size)
	{
		if (is_integer(argv[i]) == -1)
			ft_error_handler(ERROR_INTEGER, numbers);
		number = ft_atol(argv[i]);
		if (number < INT_MIN || number > INT_MAX)
			ft_error_handler(ERROR_MAXINT, numbers);
		numbers[j] = (int) number;
		i++;
		j++;
	}
	if (is_duplicated(numbers, size) == -1)
		ft_error_handler(ERROR_DUPLICATED, numbers);
	return (numbers);
}
