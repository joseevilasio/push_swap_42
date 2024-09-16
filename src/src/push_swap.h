/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:38:36 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/16 23:07:05 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

# define SUCCESS 0
/* Internal process failure range 100 | perror() */
# define ERROR_MALLOC 101
/* External process failure range 200 | ft_printf() */
# define ERROR_INTEGER 201
# define ERROR_MAXINT 202
# define ERROR_DUPLICATED 203

/* Operations */
void	swap(int *stack_a, int *stack_b, char task, int len_a, int len_b);

/* Utils */
long	ft_atol(const char *str);
int		is_integer(char *str);
int		is_duplicated(int *numbers, int size);
int		is_sorted(int *numbers, int size);

void	ft_error_handler(int signal, int *numbers);

#endif //PUSH_SWAP_H