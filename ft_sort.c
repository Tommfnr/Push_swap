/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:49:28 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/26 15:27:01 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sort(long *stack_a, int argc)
{
    int i;
    int j;
    int min_index;
    int temp;

	i = 0;
    while (i < argc - 1)
	{
        min_index = i;
        j = i + 1;
        while (j < argc) 
		{
            if (stack_a[j] < stack_a[min_index]) 
                min_index = j;
            j++;
        }
        if (min_index != i)
		{
            temp = stack_a[i];
            stack_a[i] = stack_a[min_index];
            stack_a[min_index] = temp;
        }
        i++;
    }
	return (0);
}

int		ft_stack_sorted(long *stack_a, int argc)
{
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
		{
			// printf("ce n'est pas trier prout\n");
			return (0);
		}
		i++;
	}
	// printf("trier\n");
	return (1);
}
