/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:20:42 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/16 20:14:28 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h> //retirar
#include <stdio.h> //retirar

int	check(char **argv, int size)
{
	int	i;
	long	number;

	i = 1;
	while (i < size)
	{
		if (!is_integer(argv[i]))
			return (-1);
		number = ft_atol(argv[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (-1);
		//insert em stack_a
		printf("arg -> %s\n", argv[i]);
		printf("convert -> %ld\n", number);
		printf("original -> %ld\n", atol(argv[i]));
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	/* 	int numeros_a[] = {2, 1, 3, 6, 3, 8};
	int numeros_b[] = {9, 4, 5};
	int i = 0;
	int	len_a = sizeof(numeros_a) / sizeof(numeros_a[0]); //modificar
	int	len_b = sizeof(numeros_b) / sizeof(numeros_b[0]); //modificar */

	if (argc <= 2)
		return (1);
	char **other = argv;
	other = NULL;
	if (check(argv, argc))
		return (ft_printf("Error\n"));

/* 	//swap(numeros_a, numeros_b, 's', len_a, len_b);
	ft_printf(" -- stack a -- \n");
	while (i < len_a)
	{
		ft_printf("%d\n", numeros_a[i]);
		i++;
	}
	i = 0;
	ft_printf(" -- stack b -- \n");
	while (i < len_b)
	{
		ft_printf("%d\n", numeros_b[i]);
		i++;
	}
	ft_printf("running... "); */
	ft_printf("running... ");
	return (0);
}