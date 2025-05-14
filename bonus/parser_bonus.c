/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:35:25 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/29 17:31:01 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	while (*strs)
	{
		i++;
		strs++;
	}
	return (i);
}
