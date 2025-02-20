/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_cost_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:34:02 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/20 21:05:42 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int ft_find_good_place_b(long *stack_a, long *stack_b, int argc, long element)
{
	int good_place;
	// int size_b;

	// size_b = ft_size(argc, stack_a, stack_b, 1);
	good_place = 0;
	while (good_place < 4 && stack_b[good_place] > element)
		good_place++;
	return (good_place);
}

int  ft_countc_aup_bup(long *stack_a, long *stack_b, int argc, long element)
{
	int		cost;
	// int		size_a;
	size_t		good_place;
	
	cost = 0;
	good_place = ft_find_good_place_b(stack_a, stack_b, argc, element);
	if (element != stack_a[0])
	{
		// size_a = ft_size(argc, stack_a, stack_b, 0);
		while (element != stack_a[cost] && cost < 4)
			cost++;
	}
	if (good_place > cost)
		return (good_place);
	if (good_place < cost)
		return (cost);
	return (cost);
}

// int  ft_countc_aup_bdown(long stack_a, long stack_b, int argc)
// int  ft_countc_adown_bup(long stack_a, long stack_b, int argc)
// int  ft_countc_adown_bdown (long stack_a, long stack_b, int argc)


//tester

int main ()
{
	long	stack_a[] = {2, 1, 7, 5, 6};
	long	stack_b[] = {3, 9, 4, 10, -2};
	int 	argc = 5;
	// int		i = 0;

	printf("%d\n", ft_countc_aup_bup(stack_a, stack_b, argc, 2));
	return (0);
}