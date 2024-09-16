/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:20:42 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/16 23:11:58 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_numbers(char **argv, int size)
{
	int		i;
	int		j;
	long	number;
	int		*numbers;

	i = 1;
	j = 0;
	numbers = (int *) malloc(size * sizeof(int));
	if (!numbers)
		ft_error_handler(ERROR_MALLOC, numbers);
	while (i <= size)
	{
		if (is_integer(argv[i]) == -1)
			ft_error_handler(ERROR_INTEGER, numbers);
		number = ft_atol(argv[i]);
		if (number < INT_MIN || number > INT_MAX) //rever
			ft_error_handler(ERROR_MAXINT, numbers);
		numbers[j] = (int) number;
		i++;
		j++;
	}
	if (is_duplicated(numbers, size) == -1)
		ft_error_handler(ERROR_DUPLICATED, numbers);
	return (numbers);
}

int	main(int argc, char **argv)
{
	/* 	int numeros_a[] = {2, 1, 3, 6, 3, 8};
	int numeros_b[] = {9, 4, 5};
	int	len_a = sizeof(numeros_a) / sizeof(numeros_a[0]); //modificar
	int	len_b = sizeof(numeros_b) / sizeof(numeros_b[0]); //modificar */
	int i = 0;
	int	*numbers;

	if (argc <= 2)
		return (1);
	numbers = get_numbers(argv, argc - 1);
	if (is_sorted(numbers, argc - 1))
		ft_error_handler(0, numbers);
	while (i < argc - 1)
	{
		ft_printf("%d\n", numbers[i]);
		i++;
	}
/* 	//swap(numeros_a, numeros_b, 's', len_a, len_b);
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

/* 

#TODO
> Consertar is_sorted

 */