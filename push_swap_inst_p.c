/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:49 by tfournie          #+#    #+#             */
/*   Updated: 2025/03/03 12:25:18 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_pa_bis(long *stack_a, long *stack_b, int size_a, int size_b)
{
	long	temp;
	int		i;

	i = size_a - 1;
	while (i > 0)
	{
		temp = stack_a[i];
		stack_a[i] = stack_a[i - 1];
		stack_a[i - 1] = temp;
		i--;
	}
	stack_a[0] = stack_b[0];
	i = 0;
	while (i < size_b - 1)
	{
		temp = stack_b[i + 1];
		stack_b[i + 1] = stack_b[i];
		stack_b[i] = temp;
		i++;
	}
	stack_b[size_b - 1] = (long)INT_MAX + 1;
}

char	*ft_push_pa(long *stack_a, long *stack_b, int argc)
{
	int	size_a;
	int	size_b;

	if (stack_b[0] != (long)INT_MAX + 1)
	{
		size_b = ft_size(argc, &stack_a, &stack_b, 1);
		size_a = ft_size(argc, &stack_a, &stack_b, 0);
		ft_push_pa_bis(stack_a, stack_b, size_a, size_b);
		ft_printf("pa\n");
		return ("pa");
	}
	return (NULL);
}

static void	ft_push_pb_bis(long *stack_a, long *stack_b, int size_a, int size_b)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size_b)
	{
		temp = stack_b[size_b - 1];
		stack_b[size_b - 1] = stack_b[size_b];
		stack_b[size_b] = temp;
		size_b--;
	}
	stack_b[0] = stack_a[0];
	stack_a[0] = (long)INT_MAX + 1;
	i = 0;
	while (i < size_a - 1)
	{
		temp = stack_a[i + 1];
		stack_a[i + 1] = stack_a[i];
		stack_a[i] = temp;
		i++;
	}
	stack_a[size_a - 1] = (long)INT_MAX + 1;
}

char	*ft_push_pb(long *stack_a, long *stack_b, int argc)
{
	int	size_a;
	int	size_b;

	if (stack_a[0] != (long)INT_MAX + 1)
	{
		size_b = ft_size(argc, &stack_a, &stack_b, 1);
		size_a = ft_size(argc, &stack_a, &stack_b, 0);
		ft_push_pb_bis(stack_a, stack_b, size_a, size_b);
		ft_printf("pb\n");
		return ("pb");
	}
	return (NULL);
}
