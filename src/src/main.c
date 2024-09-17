/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:20:42 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/17 21:16:21 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_numbers(char **argv, int size)
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

int	main(int argc, char **argv)
{
	int		*numbers;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc <= 2)
		ft_error_handler(ERROR_ARGS, NULL);
	numbers = get_numbers(argv, argc - 1);
	if (is_sorted(numbers, argc - 1))
		ft_error_handler(ERROR_SORTED, numbers);
	stack_b = (t_list *) malloc(sizeof(t_list));
	if (!stack_b)
		ft_error_handler(ERROR_MALLOC, numbers);
	stack_b = NULL;
	stack_a = build_stack(numbers, argc - 1);	
	print_stack(stack_a, 'A');
	radix(&stack_a, &stack_b);
	print_stack(stack_a, 'A');
	free(numbers);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
