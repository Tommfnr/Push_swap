/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:18 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/25 15:26:26 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* long	ft_find_min_cost(long **array_cost, int size_a)
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
	
}
 */