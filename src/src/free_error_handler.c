/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:48:32 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/25 22:58:37 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_handler(int signal, int *numbers, char **strs, int argc)
{
	if (signal >= 200 && signal < 300)
		ft_printf("Error\n");
	if (numbers)
		free(numbers);
	if (strs && argc == 2)
		ft_free_argv(strs);
	exit (signal);
}

void	ft_free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	ft_free_stack(t_stack *lst)
{
	t_stack	*temp;

	if (lst)
	{
		while (lst)
		{
			temp = lst->next;
			free(lst); 
			lst = temp;
		}
		lst = NULL;
	}
}
