/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:18 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/19 18:14:20 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_sort(long *stack_a, long *stack_b, int argc)
{
	int size_a;

	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	if (ft_stack_sorted(stack_a, argc) == 0)
	{
		if (size_a == 2)
			ft_swap_ab(stack_a, stack_b, 0);
		else if (size_a == 3)
			ft_sort_three(stack_a, stack_b, argc);
	}
}

void ft_sort_three(long *stack_a, long *stack_b, int argc)
{
	long	*ptr_indx_max_nb;
	long	indx_max;

	ptr_indx_max_nb = ft_find_indx_max_a(stack_a, stack_b, argc);
	indx_max = ptr_indx_max_nb - stack_a;
	if (indx_max == 0)
		ft_rotate_ab(stack_a, stack_b, argc, 0);
	else if (indx_max == 1)
		ft_reverse_rotate_ab(stack_a, stack_b, argc, 0);
	if (stack_a[0] > stack_a[1])
		ft_swap_ab(stack_a, stack_b, 0);	
}

// void ft_sort_stack(long *stack_a, long *stack_b, int argc)
// {
// 	int		size_a;

// 	size_a = ft_size(argc, &stack_a, &stack_b, 0);
// 	if (size_a-- > 3 && !ft_stack_sorted(stack_a, argc))
// 		ft_push_pb(stack_a, stack_a, argc);
// 	if (size_a-- > 3 && !ft_stack_sorted(stack_a, argc))
// 		ft_push_pb(stack_a, stack_a, argc);
// 	while (size_a-- >3 && !ft_stack_sorted(stack_a, argc))
// 	{
		
// 	}
// }
// void	ft_init_nodes_a(long *stack_a, *long stack_b, argc)
// {
// 	ft_current_index(stack_a, agrc)
// }

// void	ft_current_index(stack_a, argc)
// {
// 	int		i;
// 	int		median;
	
// }