/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:22:52 by tfournie          #+#    #+#             */
/*   Updated: 2025/03/03 12:23:19 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_swap_ab(long *stack_a, long *stack_b, int inst)
{
	long	temp;

	if (inst == 0 && stack_a && stack_a[1] != (long)INT_MAX + 1)
	{
		temp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp;
		ft_printf("sa\n");
		return ("sa");
	}
	if (inst == 1 && stack_b && stack_b[1] != (long)INT_MAX + 1)
	{
		temp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp;
		ft_printf("sb\n");
		return ("sb");
	}
	return (NULL);
}

char	*ft_swap_ss(long *stack_a, long *stack_b)
{
	long	temp;
	long	max;

	max = (long)INT_MAX + 1;
	if (stack_a && stack_a[1] != max && stack_b && stack_b[1] != max)
	{
		temp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp;
		temp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp;
		ft_printf("ss\n");
		return ("ss");
	}
	return (NULL);
}
