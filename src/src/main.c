/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:20:42 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/28 21:40:39 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_numbers(int argc, char **argv, int size)
{
	int		i;
	int		j;
	long	number;
	int		*numbers;

	i = 0;
	j = 0;
	numbers = (int *) malloc(size * sizeof(int));
	if (!numbers)
		ft_error_handler(ERROR_MALLOC, numbers, argv, argc);
	while (i < size)
	{
		if (is_integer(argv[i]) == -1)
			ft_error_handler(ERROR_INTEGER, numbers, argv, argc);
		number = ft_atol(argv[i]);
		if (number < INT_MIN || number > INT_MAX)
			ft_error_handler(ERROR_MAXINT, numbers, argv, argc);
		numbers[j] = (int) number;
		i++;
		j++;
	}
	if (is_duplicated(numbers, size) == -1)
		ft_error_handler(ERROR_DUPLICATED, numbers, argv, argc);
	return (numbers);
}

static char	**manage_args(int argc, char **argv)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv[1])
			ft_error_handler(ERROR_ARGS, NULL, argv, argc);
		return (argv);
	}
	return (argv + 1);
}

static void	manage_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stacksize(*stack_a);
	if (size == 2)
		swap(stack_a, stack_b, 'a');
	else if (size == 3)
		sort_small(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int		*numbers;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ERROR_ARGS);
	argv = manage_args(argc, argv);
	size = ft_strslen(argv);
	numbers = get_numbers(argc, argv, size);
	if (argc == 2)
		ft_free_argv(argv);
	if (is_sorted(numbers, size))
		ft_error_handler(ERROR_SORTED, numbers, NULL, argc);
	stack_a = build_stack(numbers, size);
	stack_b = NULL;
	manage_sort(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (SUCCESS);
}
