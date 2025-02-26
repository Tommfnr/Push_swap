/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:38 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/26 15:54:36 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	long	*stack_a;
	long	*stack_b;
		
	if (ft_check_error(argc, argv) == NULL)
		return (0);
	argc--;
	if (ft_init_stack(argc, argv, &stack_a, &stack_b) == -1)
		return (1);
		
	// //
	// int	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	// int		i = 0;
	// while (i < size_a)
	// {
	// 	printf("%ld   %ld\n", stack_a[i], stack_b[i]);
	// 	i++;
	// }
	// printf("\n");
	// //
	
	ft_algo_sort(stack_a, stack_b, argc);
	
	// //
	// i = 0;
	// printf("\n");
	// while (i < size_a)
	// {
	// 	printf("%ld   %ld\n", stack_a[i], stack_b[i]);
	// 	i++;
	// }
	// printf("\n");
	// //
	
	if (!ft_stack_sorted(stack_a, argc))
		return (0);
	free(stack_a);
	free(stack_b);
	return (0);
}
