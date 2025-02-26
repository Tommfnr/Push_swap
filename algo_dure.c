/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:16:14 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/26 12:53:08 by tfournie         ###   ########.fr       */
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
			ft_sort_three(stack_a, stack_b, argc, 0);
		else if (size_a == 4)
			ft_sort_four(stack_a, stack_b, argc);
		else if (size_a == 5)
			ft_sort_five(stack_a, stack_b, argc);
		else
		{
			ft_push_pb(stack_a, stack_b, argc);
			ft_push_pb(stack_a, stack_b, argc);
			ft_push_pb(stack_a, stack_b, argc);
			ft_sort_three(stack_a, stack_b, argc, 1);
			ft_exe_algo(stack_a, stack_b, argc);
		}
	}
}

void ft_sort_three(long *stack_a, long *stack_b, int argc, int witch)
{
	long	*ptr_indx_max_nb;
	long	indx_max;

	if (witch == 0)
	{
		ptr_indx_max_nb = ft_find_indx_max_a(stack_a, stack_b, argc);
		indx_max = ptr_indx_max_nb - stack_a;
		if (indx_max == 0)
			ft_rotate_ab(stack_a, stack_b, argc, 0);
		else if (indx_max == 1)
			ft_reverse_rotate_ab(stack_a, stack_b, argc, 0);
		if (stack_a[0] > stack_a[1])
			ft_swap_ab(stack_a, stack_b, 0);
	}
	else
	{
		ptr_indx_max_nb = ft_find_indx_max_b(stack_a, stack_b, argc);
		indx_max = ptr_indx_max_nb - stack_b;
		if (indx_max == 0)
			ft_reverse_rotate_ab(stack_a, stack_b, argc, 1);
		else if (indx_max == 1)
			ft_rotate_ab(stack_a, stack_b, argc, 1);
		if (stack_b[0] < stack_b[1])
			ft_swap_ab(stack_a, stack_b, 1);
	}	
}

void ft_push_min_a(long *stack_a, long *stack_b, int argc)
{
	long	*ptr_indx_min_nb;
	long	indx_min;

	ptr_indx_min_nb = ft_find_indx_min_a(stack_a, stack_b, argc);
	indx_min = ptr_indx_min_nb - stack_a;
	while (indx_min > 0)
	{
		ft_rotate_ab(stack_a, stack_b, argc, 0);
		indx_min--;
	}
	ft_push_pb(stack_a, stack_b, argc);
}

void ft_sort_four(long *stack_a, long *stack_b, int argc)
{
	int		size_a;

	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	if (ft_stack_sorted(stack_a, argc) == 1)
		return ;
	if (size_a == 4)
	{
		ft_push_min_a(stack_a, stack_b, argc);
		ft_sort_three(stack_a, stack_b, argc, 0);
		ft_push_pa(stack_a, stack_b, argc);
	}
}

void ft_sort_five(long *stack_a, long *stack_b, int argc)
{
	ft_push_min_a(stack_a, stack_b, argc);
	ft_push_min_a(stack_a, stack_b, argc);
	ft_sort_three(stack_a, stack_b, argc, 0);
	ft_push_pa(stack_a, stack_b, argc);
	ft_push_pa(stack_a, stack_b, argc);
}
