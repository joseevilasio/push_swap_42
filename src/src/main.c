/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:20:42 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/23 22:49:24 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	manage_sort(t_stack **stack_a, t_stack **stack_b)
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
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	stack_b = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_b)
		ft_error_handler(ERROR_MALLOC, numbers);
	stack_b = NULL;
	stack_a = build_stack(numbers, argc - 1);
	free(numbers);
	manage_sort(&stack_a, &stack_b);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	// ft_lstclear(&stack_a, free);
	// ft_lstclear(&stack_b, free);
	return (0);
}
