/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst_rr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:28:59 by tfournie          #+#    #+#             */
/*   Updated: 2025/03/03 13:59:43 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_reverse_rotate_a(long *stack_a, long *stack_b, int argc)
{
	long	temp;
	int		i;
	int		size_a;

	i = 0;
	if (stack_a && stack_a[1] != (long)INT_MAX + 1)
	{
		size_a = ft_size(argc, &stack_a, &stack_b, 0);
		i = size_a - 1;
		temp = stack_a[size_a - 1];
		while (i > 0)
		{
			stack_a[i] = stack_a[i - 1];
			i--;
		}
		stack_a[0] = temp;
		ft_printf("rra\n");
		return ("rra");
	}
	return (NULL);
}

char	*ft_reverse_rotate_b(long *stack_a, long *stack_b, int argc)
{
	long	temp;
	int		i;
	int		size_b;

	i = 0;
	if (stack_b && stack_b[1] != (long)INT_MAX + 1)
	{
		size_b = ft_size(argc, &stack_a, &stack_b, 1);
		i = size_b - 1;
		temp = stack_b[size_b - 1];
		while (i > 0)
		{
			stack_b[i] = stack_b[i - 1];
			i--;
		}
		stack_b[0] = temp;
		ft_printf("rrb\n");
		return ("rrb");
	}
	return (NULL);
}

char	*ft_reverse_rotate_ab(long *stack_a, long *stack_b, int argc, int inst)
{
	if (inst == 0)
		return (ft_reverse_rotate_a(stack_a, stack_b, argc));
	if (inst == 1)
		return (ft_reverse_rotate_b(stack_a, stack_b, argc));
	return (NULL);
}

char	*ft_reverse_rotate_rrr(long *stack_a, long *stack_b, int argc)
{
	long	temp;
	int		i;
	int		size_a;
	int		size_b;

	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	size_b = ft_size(argc, &stack_a, &stack_b, 1);
	if (stack_a && stack_a[1] != (long)INT_MAX + 1 && stack_b
		&& stack_b[1] != (long)INT_MAX + 1)
	{
		i = size_a;
		temp = stack_a[size_a - 1];
		while (--i > 0)
			stack_a[i] = stack_a[i - 1];
		stack_a[0] = temp;
		i = size_b;
		temp = stack_b[size_b - 1];
		while (--i > 0)
			stack_b[i] = stack_b[i - 1];
		stack_b[0] = temp;
		ft_printf("rrr\n");
		return ("rrr");
	}
	return (NULL);
}
