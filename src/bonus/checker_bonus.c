/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:42:56 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/29 20:01:09 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

static int	exec_cmd(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (ft_strncmp(cmd, "pa\n", 3) == 0)
		push(stack_a, stack_b, 'a');
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		push(stack_a, stack_b, 'b');
	else if (ft_strncmp(cmd, "sa\n", 3) == 0)
		swap(stack_a, stack_b, 'a');
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		swap(stack_a, stack_b, 'b');
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		rotate(stack_a, stack_b, 'a');
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rotate(stack_a, stack_b, 'b');
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rotate(stack_a, stack_b, 'r');
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rrotate(stack_a, stack_b, 'a');
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rrotate(stack_a, stack_b, 'b');
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rrotate(stack_a, stack_b, 'r');
	else
		return (-1);
	return (0);
}

static void	execute(t_stack **stack_a, t_stack **stack_b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (exec_cmd(stack_a, stack_b, cmd) == -1)
		{
			ft_free_stack(stack_a);
			ft_free_stack(stack_b);
			free(cmd);
			close(0);
			ft_error_handler(ERROR_CMD, NULL, NULL, 0);
		}
		free(cmd);
		cmd = get_next_line(0);
	}
	if (ft_stack_sorted(*stack_a) == 0 && ft_stacksize(*stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
	stack_a = build_stack(numbers, size);
	stack_b = NULL;
	execute(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (SUCCESS);
}
