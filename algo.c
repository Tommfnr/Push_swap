/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:18 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/25 18:11:48 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_find_min_cost(long **array_cost, int size_a)
{
	int		i;
	int		j;
	long	min_cost;

	i = 1;
	min_cost = array_cost[0][0];
	while(i < size_a)
	{
		j = 0;
		while (j < 4)
		{
			if (min_cost > array_cost[i][j])
				min_cost = array_cost[i][j];
			j++;
		}
		i++;
	}
	return (min_cost);	
}

int	ft_col_min_cost(long **array_cost, int size_a, int element)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < size_a)
	{
		j = 0;
		while (j < 4)
		{
			if (array_cost[i][j] == element)
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int	ft_line_min_cost(long **array_cost, int size_a, int element)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < size_a)
	{
		j = 0;
		while (j < 4)
		{
			if (array_cost[i][j] == element)
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

void	ft_processe_min_cost(long *stack_a, long *stack_b, int argc, long **array_cost)
{
	int		size_a;
	int		min_cost;
	int		lin;
	int		col;

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

void	ft_exe_algo(long *stack_a, long *stack_b, int argc)
{
	int		size_a;
	int		i;
	long 	**array_cost;
	long	*ptr_indx_max_nb;
	int		indx_max;

	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	i = 0;
	while (stack_a[0] != (long) INT_MAX + 1 && i < size_a)
	{
		array_cost = ft_init_array_cost(stack_a, stack_b, argc);
		ft_processe_min_cost(stack_a, stack_b, argc, array_cost);
		ft_free_array(stack_a, stack_b, argc, array_cost);
		i++;
	}
	ptr_indx_max_nb = ft_find_indx_max_b(stack_a, stack_b, argc);
	indx_max = ptr_indx_max_nb - stack_a;
	i = 0;
	while (i < indx_max)
	{
		ft_rotate_ab(stack_a, stack_b, argc, 0);
		i++;
	}
	i = 0;
	while (stack_b[0] != (long) INT_MAX + 1 && i < size_a)
	{
		ft_push_pa(stack_a, stack_b, argc);
		i++;
	}
}
