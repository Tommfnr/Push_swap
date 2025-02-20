/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:38 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/20 20:03:35 by tfournie         ###   ########.fr       */
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
	int		i = 0;
	// int		test = 0;
	
	if (ft_check_error(argc, argv) == NULL)
		return (0);
	argc--;
	if (ft_init_stack(argc, argv, &stack_a, &stack_b) == -1)
		return (1);
	printf("\n");
	while (i < argc)
	{
		printf("%ld   %ld\n", stack_a[i], stack_b[i]);
		i++;
	}
	ft_algo_sort(stack_a, stack_b, argc);
	i = 0;
	while (i < argc)
	{
		printf("%ld   %ld\n", stack_a[i], stack_b[i]);
		i++;
	}
	if (!ft_stack_sorted(stack_a, argc))
		return (0);
	i = 0;
	// while (i < argc)
	// {
	// 	printf("%ld   %ld\n", stack_a[i], stack_b[i]);
	// 	i++;
	// }
	// ft_random();
	// ft_swap_ab(stack_a, stack_b, 0);
	// ft_push_pb(stack_a, stack_b, argc);
	// ft_push_pb(stack_a, stack_b, argc);
	// ft_push_pb(stack_a, stack_b, argc);
	// ft_swap_ab(stack_a, stack_b, 0);
	// ft_push_pa(stack_a, stack_b, argc);
	// ft_push_pa(stack_a, stack_b, argc);
	// ft_push_pa(stack_a, stack_b, argc);
	// ft_swap_ss(stack_a, stack_b);
	// ft_push_pb(stack_a, stack_b, argc);
	// ft_push_pb(stack_a, stack_b, argc);
	// ft_swap_ss(stack_a, stack_b);
	// ft_push_pb(stack_a, stack_b, argc);
	// ft_push_pb(stack_a, stack_b, argc);
	// while (test < 1) //combien d'instruction
	// {
	// 	// printf("\n%d\n\n", size(argc, &stack_a, &stack_b, 0));
	// 	// ft_swap(stack_a, stack_b, "sa");
	// 	printf("\n%s\n",ft_reverse_rotate_rrr(stack_a, stack_b, argc));
	// 	i = 0;
	// 	while (i < argc)
	// 	{
	// 		printf("< %ld | %ld >\n", stack_a[i], stack_b[i]);
	// 		i++;
	// 	}
	// 	test++;
	// }
	i = 0;
	// printf("\n");
	// while (i < argc)
	// {
	// 	printf("%ld   %ld\n", stack_a[i], stack_b[i]);
	// 	i++;
	// }
	free(stack_a);
	free(stack_b);
	return (0);
}
