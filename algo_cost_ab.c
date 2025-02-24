/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_cost_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:34:02 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/24 18:28:26 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int  ft_countc_aup_bup(long *stack_a, long *stack_b, int argc, long element)
{
	int		cost;
	// int		size_a;
	int		good_place;
	
	cost = 0;
	good_place = ft_find_good_place_bup(stack_a, stack_b, argc, element);
	if (element != stack_a[0])
	{
		// size_a = ft_size(argc, stack_a, stack_b, 0);
		while (element != stack_a[cost] && cost < /*size_a*/5)
			cost++;
	}
	else
		return (good_place);
	if (good_place > cost)
		return (good_place);
	if (good_place < cost)
		return (cost);
	return (cost);
}

int  ft_countc_aup_bdown(long *stack_a, long *stack_b, int argc, long element)
{
	int		cost;
	// int		size_b;
	// int		size_a;
	int		good_place;
	
	cost = 0;
	// size_b = ft_size(argc, stack_a, stack_b, 0);
	good_place = (ft_find_good_place_bdown(stack_a, stack_b, argc, element));
	if (good_place == /*size_b*/5)
		good_place = 1;
	if (element != stack_a[0])
	{
		// size_a = ft_size(argc, stack_a, stack_b, 0);
		while (element != stack_a[cost] && cost < /*size_a*/5)
			cost++;
	}
	else
		return (good_place);
	return (cost + good_place);
}

int  ft_countc_adown_bup(long *stack_a, long *stack_b, int argc, long element)
{
	int		cost;
	// int		size_b;
	// int		size_a;
	int		good_place;
	
	cost = 0;
	// size_b = ft_size(argc, stack_a, stack_b, 0);
	good_place = (ft_find_good_place_bup(stack_a, stack_b, argc, element));
	if (good_place == /*size_b*/5)
		good_place = 1;
	if (element != stack_a[0])
	{
		// size_a = ft_size(argc, stack_a, stack_b, 0);
		while (element != stack_a[cost] && cost < /*size_a*/5)
			cost++;
	}
	else
		return (good_place);
	return ((/*size_a*/5 - cost) + good_place);
}

int  ft_countc_adown_bdown(long *stack_a, long *stack_b, int argc, long element)
{
	int		cost;
	// int		size_a;
	int		good_place;
	
	cost = 0;
	good_place = ft_find_good_place_bdown(stack_a, stack_b, argc, element);
	if (element != stack_a[0])
	{
		// size_a = ft_size(argc, stack_a, stack_b, 0);
		while (element != stack_a[cost] && cost < /*size_a*/5)
			cost++;
	}
	else
		return (good_place);
	cost = /*size_a*/5 - cost;
	if (good_place > cost)
		return (good_place);
	if (good_place < cost)
		return (cost);
	return (cost);
}

//tester

/* int main ()
{
	long	stack_a[] = {2, 8, 5, 10, 1, (long) INT_MAX + 1, (long) INT_MAX + 1, (long) INT_MAX + 1, (long) INT_MAX + 1, (long) INT_MAX + 1};
	long	stack_b[] = {3, 9, 7, 6, 4, (long) INT_MAX + 1, (long) INT_MAX + 1, (long) INT_MAX + 1, (long) INT_MAX + 1, (long) INT_MAX + 1};
	int 	argc = 10;
	int		i = 3;

	printf("%d\n", ft_countc_aup_bup(stack_a, stack_b, argc, i));
	printf("%d\n", ft_countc_aup_bdown(stack_a, stack_b, argc, i));
	printf("%d\n", ft_countc_adown_bup(stack_a, stack_b, argc, i));
	printf("%d\n", ft_countc_adown_bdown(stack_a, stack_b, argc, i));
	return (0);
} */