/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:33:59 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/26 18:24:25 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_count_cost_element(long *stack_a, long *stack_b, int argc, long **array_cost)
{
	int		i;
	int		size_a;

	i = 0;
	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	while (i < size_a)
	{
		array_cost[i] = malloc(4 * sizeof(long));
		if (!array_cost[i])
		{
			free(array_cost);
			return ;
		}
		array_cost[i][0] = ft_countc_aup_bup(stack_a, stack_b, argc, stack_a[i]);
		array_cost[i][1] = ft_countc_aup_bdown(stack_a, stack_b, argc, stack_a[i]);
		array_cost[i][2] = ft_countc_adown_bup(stack_a, stack_b, argc, stack_a[i]);
		array_cost[i][3] = ft_countc_adown_bdown(stack_a, stack_b, argc, stack_a[i]);
		i++;
	}
	return ;
}

void	ft_free_array(long *stack_a, long *stack_b, int argc, long **array_cost)
{
	int		i;
	int		size_a;
	
	i = 0;
	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	while (i < size_a + 1)
	{
		free(array_cost[i]);
		i++;
		printf("Libération\n");
	}
	free(array_cost);
	printf("Libération de array_cost\n");
}

long	**ft_init_array_cost(long *stack_a, long *stack_b, int argc)
{
	long	**array_cost;
	int		size_a;

	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	array_cost = malloc(size_a * sizeof(long *));
	if (!array_cost)
		return (0);
	ft_count_cost_element(stack_a, stack_b, argc, array_cost);
	
	// //
	// for (int i = 0; i < size_a; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         printf("%ld ", array_cost[i][j]);
    //     }
    //     printf("\n");
    // }
	// //
	
	return(array_cost);
}


/* int main ()
{
	long	stack_a[] = {2, 8, 5, 10, 1, (long) INT_MAX + 1, (long) INT_MAX + 1, (long) INT_MAX + 1, (long) INT_MAX + 1, (long) INT_MAX + 1};
	long	stack_b[] = {3, 9, 7, 6, 4, (long) INT_MAX + 1, (long) INT_MAX + 1, (long) INT_MAX + 1, (long) INT_MAX + 1, (long) INT_MAX + 1};
	int 	argc = 10;
	int		i = 3;

	ft_count_cost_stack(stack_a, stack_b, argc);
	return (0);
} */