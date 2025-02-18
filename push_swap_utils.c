/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:44 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/18 19:41:07 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_tri(int *stack_a, int len)
{
    int i;
    int j;
    int min_index;
    int temp;

	i = 0;
    while (i < len - 1)
	{
        min_index = i;
        j = i + 1;
        while (j < len) 
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