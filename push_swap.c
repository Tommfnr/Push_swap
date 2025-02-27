/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:38 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/27 19:12:18 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	long	*stack_a;
	long	*stack_b;
		
	if (ft_check_error(argc, argv) == NULL)
		return (0);
	argc--;
	if (ft_init_stack(argc, argv, &stack_a, &stack_b) == -1)
		return (1);
	ft_algo_sort(stack_a, stack_b, argc);
	free(stack_a);
	free(stack_b);
	return (0);
}
