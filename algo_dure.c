/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomm <tomm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:16:14 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/24 23:21:34 by tomm             ###   ########.fr       */
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
		else if (size_a == 4)
			ft_sort_four(stack_a, stack_b, argc);
		else if (size_a == 5)
			ft_sort_four(stack_a, stack_b, argc);
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

static void ft_psuh_min_a(long *stack_a, long *stack_b, int argc)
{
	int		min_indx;

	min_indx = *ft_find_indx_min_a(stack_a, stack_b, argc);
	while (min_indx > 0)
	{
		ft_rotate_ab(stack_a, stack_b, argc, 0);
		min_indx--;
	}
	ft_push_pb(stack_a, stack_b, argc);
}

void ft_sort_four(long *stack_a, long *stack_b, int argc)
{
	int		size_a;

	size_a = ft_size(argc, stack_a, stack_b, 0);
	if (ft_stack_sorted(stack_a, argc) == 0)
		return ;
	if (size_a == 4)
	{
		ft_psuh_min_a(stack_a, stack_b, argc);
		ft_sort_three(stack_a, stack_b, argc);
		ft_push_pa(stack_a, stack_b, argc);
	}
}

void ft_sort_five(long *stack_a, long *stack_b, int argc)
{
	int		size_a;

	size_a = ft_size(argc, stack_a, stack_b, 0);
	if (ft_stack_sorted(stack_a, argc) == 0)
		return ;
	if (size_a == 5)
	{
		ft_psuh_min_a(stack_a, stack_b, argc);
		ft_psuh_min_a(stack_a, stack_b, argc);
		ft_sort_three(stack_a, stack_b, argc);
		ft_push_pa(stack_a, stack_b, argc);
		ft_push_pa(stack_a, stack_b, argc);
	}
}
