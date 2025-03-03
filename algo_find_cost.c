/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_find_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:46:51 by tfournie          #+#    #+#             */
/*   Updated: 2025/03/03 11:49:14 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_find_min_cost(long **array_cost, int size_a)
{
	int		i;
	int		j;
	long	min_cost;

	i = 0;
	min_cost = array_cost[0][0];
	while (i < size_a)
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
	int	i;
	int	j;

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
	int	i;
	int	j;

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
