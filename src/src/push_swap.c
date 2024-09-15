/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:20:42 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/15 19:07:50 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	int numeros_a[] = {2, 1, 3, 6, 3, 8};
	int numeros_b[] = {9, 4, 5};
	int i = 0;
	int	len_a = sizeof(numeros_a) / sizeof(numeros_a[0]); //modificar
	int	len_b = sizeof(numeros_b) / sizeof(numeros_b[0]); //modificar

	swap(numeros_a, numeros_b, 's', len_a, len_b);
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
	ft_printf("running... ");
	return (0);
}