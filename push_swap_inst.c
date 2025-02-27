/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:49 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/27 20:10:41 by tfournie         ###   ########.fr       */
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

char	*ft_push_pa(long *stack_a, long *stack_b, int argc)
{
	long	temp;
	int		i;
	int		size_a;
	int		size_b;

	i = 0;
	if (stack_b[0] != (long)INT_MAX + 1)
	{
		size_b = ft_size(argc, &stack_a, &stack_b, 1);
		size_a = ft_size(argc, &stack_a, &stack_b, 0);
		while (i < size_a)
		{
			temp = stack_a[size_a - 1];
			stack_a[size_a - 1] = stack_a[size_a];
			stack_a[size_a] = temp;
			size_a--;
		}
		stack_a[0] = stack_b[0];
		stack_b[0] = (long)INT_MAX + 1;
		i = 0;
		while (i < size_b - 1)
		{
			temp = stack_b[i + 1];
			stack_b[i + 1] = stack_b[i];
			stack_b[i] = temp;
			i++;
		}
		stack_b[size_b - 1] = (long)INT_MAX + 1;
		ft_printf("pa\n");
		return ("pa");
	}
	return (NULL);
}

char	*ft_push_pb(long *stack_a, long *stack_b, int argc)
{
	long	temp;
	int		i;
	int		size_a;
	int		size_b;

	i = 0;
	if (stack_a[0] != (long)INT_MAX + 1)
	{
		size_b = ft_size(argc, &stack_a, &stack_b, 1);
		size_a = ft_size(argc, &stack_a, &stack_b, 0);
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
		ft_printf("pb\n");
		return ("pb");
	}
	return (NULL);
}

char	*ft_rotate_ab(long *stack_a, long *stack_b, int argc, int inst)
{
	long	temp;
	int		i;
	int		size_a;
	int		size_b;

	i = 0;
	if (inst == 0 && stack_a && stack_a[1] != (long)INT_MAX + 1)
	{
		size_a = ft_size(argc, &stack_a, &stack_b, 0);
		temp = stack_a[0];
		while (i < size_a)
		{
			stack_a[i] = stack_a[i + 1];
			i++;
		}
		stack_a[size_a - 1] = temp;
		ft_printf("ra\n");
		return ("ra");
	}
	if (inst == 1 && stack_b && stack_b[1] != (long)INT_MAX + 1)
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

char	*ft_rotate_rr(long *stack_a, long *stack_b, int argc)
{
	long	temp;
	int		i;
	int		size_a;
	int		size_b;

	i = 0;
	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	size_b = ft_size(argc, &stack_a, &stack_b, 1);
	if (stack_a && stack_a[1] != (long)INT_MAX + 1 && stack_b
		&& stack_b[1] != (long)INT_MAX + 1)
	{
		temp = stack_a[0];
		while (i < size_a)
		{
			stack_a[i] = stack_a[i + 1];
			i++;
		}
		stack_a[size_a - 1] = temp;
		temp = stack_b[0];
		i = 0;
		while (i < size_b)
		{
			stack_b[i] = stack_b[i + 1];
			i++;
		}
		stack_b[size_b - 1] = temp;
		ft_printf("rr\n");
		return ("rr");
	}
	return (NULL);
}

char	*ft_reverse_rotate_ab(long *stack_a, long *stack_b, int argc, int inst)
{
	long	temp;
	int		i;
	int		size_a;
	int		size_b;

	size_a = ft_size(argc, &stack_a, &stack_b, 0);
	size_b = ft_size(argc, &stack_a, &stack_b, 1);
	if (inst == 0 && stack_a && stack_a[1] != (long)INT_MAX + 1)
	{
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
	if (inst == 1 && stack_b && stack_b[1] != (long)INT_MAX + 1)
	{
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
		i = size_a - 1;
		temp = stack_a[size_a - 1];
		while (i > 0)
		{
			stack_a[i] = stack_a[i - 1];
			i--;
		}
		stack_a[0] = temp;
		i = size_b - 1;
		temp = stack_b[size_b - 1];
		while (i > 0)
		{
			stack_b[i] = stack_b[i - 1];
			i--;
		}
		stack_b[0] = temp;
		ft_printf("rrr\n");
		return ("rrr");
	}
	return (NULL);
}
