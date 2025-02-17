/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:38 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/17 15:08:29 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

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

int	main(void)
{
	int		list[] = {12,55,44,468,1,20,5,-2};
	int		i = 0;
	int		len = sizeof(list)/sizeof(int);
	ft_tri(list, len);
	
	while (i < len)
	{
		ft_printf("trier: %d\n",list[i]);
		i++;
	}
	return (0);	
}