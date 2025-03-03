/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:27:59 by tfournie          #+#    #+#             */
/*   Updated: 2025/03/03 13:52:20 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_rotate_a(long *stack_a, long *stack_b, int argc)
{
	long	temp;
	int		i;
	int		size_a;

	i = 0;
	if (stack_a && stack_a[1] != (long)INT_MAX + 1)
	{
		size_a = ft_size(argc, &stack_a, &stack_b, 0);
		temp = stack_a[0];
		while (i < size_a - 1)
		{
			stack_a[i] = stack_a[i + 1];
			i++;
		}
		stack_a[size_a - 1] = temp;
		ft_printf("ra\n");
		return ("ra");
	}
	return (NULL);
}

char	*ft_rotate_b(long *stack_a, long *stack_b, int argc)
{
	long	temp;
	int		i;
	int		size_b;

	i = 0;
	if (stack_b && stack_b[1] != (long)INT_MAX + 1)
	{
		size_b = ft_size(argc, &stack_a, &stack_b, 1);
		temp = stack_b[0];
		while (i < size_b - 1)
		{
			stack_b[i] = stack_b[i + 1];
			i++;
		}
		stack_b[size_b - 1] = temp;
		ft_printf("rb\n");
		return ("rb");
	}
	return (NULL);
}

char	*ft_rotate_ab(long *stack_a, long *stack_b, int argc, int inst)
{
	if (inst == 0)
		return (ft_rotate_a(stack_a, stack_b, argc));
	if (inst == 1)
		return (ft_rotate_b(stack_a, stack_b, argc));
	return (NULL);
}

char	*ft_rotate_rr(long *stack_a, long *stack_b, int argc)
{
	long	temp;
	int		i;
	int		size_a;
	int		size_b;

	i = -1;
	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	size_b = ft_size(argc, &stack_a, &stack_b, 1);
	if (stack_a && stack_a[1] != (long)INT_MAX + 1 && stack_b
		&& stack_b[1] != (long)INT_MAX + 1)
	{
		temp = stack_a[0];
		while (++i < size_a)
			stack_a[i] = stack_a[i + 1];
		stack_a[size_a - 1] = temp;
		temp = stack_b[0];
		i = -1;
		while (++i < size_b)
			stack_b[i] = stack_b[i + 1];
		stack_b[size_b - 1] = temp;
		ft_printf("rr\n");
		return ("rr");
	}
	return (NULL);
}
