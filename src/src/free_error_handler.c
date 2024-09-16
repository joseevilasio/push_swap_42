/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:48:32 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/16 23:08:22 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_handler(int signal, int *numbers)
{
	if (signal >= 100 && signal < 200)
	{
		if (numbers)
			free(numbers);
		exit (signal);
	}
	else if (signal >= 200 && signal < 300)
	{
		if (numbers)
			free(numbers);
		ft_printf("Error\n");
		exit (signal);
	}
	else
	{
		if (numbers)
			free(numbers);
		exit (signal);
	}
}
