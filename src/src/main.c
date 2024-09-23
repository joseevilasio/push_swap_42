/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:20:42 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/21 18:22:58 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_numbers(char **argv, int size)
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

static	void	manage_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
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
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 1;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		ft_error_handler(ERROR_ARGS, NULL);
	if (argc == 2)
	{
		i = 0;
		argv = ft_split(argv[1], ' ');
		argc = 4; //ft len split
	}
	numbers = get_numbers(argv + i, argc - 1);
	if (is_sorted(numbers, argc - 1))
		ft_error_handler(ERROR_SORTED, numbers);
	stack_b = (t_list *) malloc(sizeof(t_list));
	if (!stack_b)
		ft_error_handler(ERROR_MALLOC, numbers);
	stack_b = NULL;
	stack_a = build_stack(numbers, argc - 1);
	free(numbers);
	manage_sort(&stack_a, &stack_b);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
