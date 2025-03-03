/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_cost_ab_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:36:54 by tfournie          #+#    #+#             */
/*   Updated: 2025/03/03 14:23:27 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_find_max_b(long *stack_a, long *stack_b, int argc)
{
	long	max;
	int		i;
	int		size_b;

	max = stack_b[0];
	i = 1;
	size_b = ft_size(argc, &stack_a, &stack_b, 1);
	while (i < size_b)
	{
		if (max < stack_b[i])
			max = stack_b[i];
		i++;
	}
	return (max);
}

int	ft_find_good_place_aup(long *stack_a, long *stack_b, int argc, long element)
{
	int	size_a;
	int	good_place;

	good_place = 0;
	if (stack_a[0] == element)
		return (0);
	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	while (good_place < size_a && element != stack_a[good_place])
		good_place++;
	return (good_place);
}

int	ft_find_good_place_adown(long *stack_a, long *stack_b, int argc,
		long element)
{
	int	size_a;
	int	good_place;
	int	i;

	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	i = size_a;
	good_place = 0;
	if (stack_a[0] == element)
		return (0);
	while (i > 0 && element != stack_a[i])
	{
		good_place++;
		i--;
	}
	return (good_place);
}

int	ft_find_good_place_bup(long *stack_a, long *stack_b, int argc, long element)
{
	long	max;
	int		i;
	int		size_b;
	int		good_place;

	max = (long)INT_MIN - 1;
	i = 0;
	good_place = 0;
	size_b = ft_size(argc, &stack_a, &stack_b, 1);
	while (i < size_b)
	{
		if (stack_b[i] < element && stack_b[i] > max)
			max = stack_b[i];
		i++;
	}
	if (i == size_b && max == (long)INT_MIN - 1)
		max = ft_find_max_b(stack_a, stack_b, argc);
	while (max != stack_b[good_place])
		good_place++;
	return (good_place);
}

int	ft_find_good_place_bdown(long *stack_a, long *stack_b, int argc,
		long element)
{
	long	max;
	int		i;
	int		size_b;
	int		good_place;

	max = (long)INT_MIN - 1;
	i = 0;
	good_place = 0;
	size_b = ft_size(argc, &stack_a, &stack_b, 1);
	while (i < size_b)
	{
		if (stack_b[i] < element && stack_b[i] > max)
			max = stack_b[i];
		i++;
	}
	if (i == size_b && max == (long)INT_MIN - 1)
		max = ft_find_max_b(stack_a, stack_b, argc);
	while (max != stack_b[good_place])
		good_place++;
	return (size_b - good_place);
}
