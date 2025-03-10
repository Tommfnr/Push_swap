/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:44 by tfournie          #+#    #+#             */
/*   Updated: 2025/03/10 12:45:58 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size(int argc, long **stack_a, long **stack_b, int witch)
{
	size_t	size;
	int		i;

	size = 0;
	i = -1;
	if (witch == 0)
	{
		while (++i < argc)
			if ((*stack_a)[size] != (long)INT_MAX + 1)
				size++;
		return (size);
	}
	if (witch == 1)
	{
		while (++i < argc)
			if ((*stack_b)[size] != (long)INT_MAX + 1)
				size++;
		return (size);
	}
	return (-1);
}

int	ft_init_stack(int argc, char **argv, long **stack_a, long **stack_b)
{
	int	i;

	i = 0;
	*stack_a = malloc((argc) * sizeof(long));
	if (!*stack_a)
		return (-1);
	*stack_b = malloc((argc) * sizeof(long));
	if (!*stack_b)
	{
		free(*stack_a);
		return (-1);
	}
	while (i < argc)
	{
		(*stack_a)[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	while (i < argc)
	{
		(*stack_b)[i] = (long)INT_MAX + 1;
		i++;
	}
	return (argc);
}
