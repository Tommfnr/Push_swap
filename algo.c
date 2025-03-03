/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:18 by tfournie          #+#    #+#             */
/*   Updated: 2025/03/03 11:51:17 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_processe_min_cost(long *stack_a, long *stack_b, int argc,
		long **array_cost)
{
	int	size_a;
	int	min_cost;
	int	lin;
	int	col;

	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	min_cost = ft_find_min_cost(array_cost, size_a);
	lin = ft_line_min_cost(array_cost, size_a, min_cost);
	col = ft_col_min_cost(array_cost, size_a, min_cost);
	if (col == 0)
		ft_do_aup_bup(stack_a, stack_b, argc, stack_a[lin]);
	if (col == 1)
		ft_do_aup_bdown(stack_a, stack_b, argc, stack_a[lin]);
	if (col == 2)
		ft_do_adown_bup(stack_a, stack_b, argc, stack_a[lin]);
	if (col == 3)
		ft_do_adown_bdown(stack_a, stack_b, argc, stack_a[lin]);
	ft_push_pb(stack_a, stack_b, argc);
}

static void	ft_exe_algo_final(long *stack_a, long *stack_b, int argc,
		int indx_max)
{
	int	i;

	i = -1;
	if (argc / 2 < indx_max)
	{
		while (++i < (argc - indx_max))
			ft_reverse_rotate_ab(stack_a, stack_b, argc, 1);
	}
	else
	{
		while (++i < indx_max)
			ft_rotate_ab(stack_a, stack_b, argc, 1);
	}
	i = -1;
	while (stack_b[0] != (long)INT_MAX + 1 && ++i < argc)
		ft_push_pa(stack_a, stack_b, argc);
}

void	ft_exe_algo(long *stack_a, long *stack_b, int argc)
{
	int		size_a;
	int		i;
	long	**array_cost;
	long	*ptr_indx_max_nb;
	int		indx_max;

	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	i = 0;
	while (stack_a[0] != (long)INT_MAX + 1 && i < size_a)
	{
		array_cost = ft_init_array_cost(stack_a, stack_b, argc);
		if (!array_cost)
			return ;
		ft_processe_min_cost(stack_a, stack_b, argc, array_cost);
		ft_free_array(stack_a, stack_b, argc, array_cost);
		i++;
	}
	ptr_indx_max_nb = ft_find_indx_max_b(stack_a, stack_b, argc);
	indx_max = ptr_indx_max_nb - stack_b;
	ft_exe_algo_final(stack_a, stack_b, argc, indx_max);
}
