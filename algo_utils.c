/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:34:19 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/25 12:55:30 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*ft_find_indx_max_a(long *stack_a, long *stack_b, int argc)
{
	long	*max;
	int			i;
	int 		size_a;

	max = &stack_a[0];
	i = 1;
	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	while (i < size_a)
	{
		if (*max < stack_a[i])
			max = &stack_a[i];
		i++;
	}
	return (max);
}

long	*ft_find_indx_max_b(long *stack_a, long *stack_b, int argc)
{
	long	*max;
	int			i;
	int 		size_b;

	max = &stack_b[0];
	i = 1;
	size_b = ft_size(argc, &stack_a, &stack_b, 1);
	while (i < size_b)
	{
		if (*max < stack_b[i])
			max = &stack_b[i];
		i++;
	}
	return (max);
}

long	*ft_find_indx_min_a(long *stack_a, long *stack_b, int argc)
{
	long	*min;
	int		i;
	int 	size_a;

	min = &stack_a[0];
	i = 1;
	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	while (i < size_a)
	{
		if (*min > stack_a[i])
			min = &stack_a[i];
		i++;
	}
	return (min);
}
