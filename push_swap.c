/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:38 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/18 19:57:08 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int		init_stack(int argc, char **argv, int long**stack_a, int long**stack_b)//recup la chaine et creer la stack_b calcule taille et regarde les erreurs
{
	int		i;

	i = 0;
	*stack_a = malloc((argc) * sizeof(int long));
	if (!*stack_a)
		return (-1);
	*stack_b = malloc((argc) * sizeof(int long));
	if (!*stack_b)
	{
		free(stack_a);
		return (-1);
	}
	while (i < argc)
	{
		(*stack_a)[i] = atoi(argv[i + 1]);
		// ft_printf("%d\n",(*stack_a)[i - 1]);
		i++;
	}
	i = 0;
	while (i < argc)
	{
		(*stack_b)[i] = (long) INT_MAX + 1;
		// ft_printf("%d\n",(*stack_a)[i - 1]);
		i++;
	}
	return (argc);
}

int	ft_size(int argc, int long **stack_a, int long **stack_b, int witch) // 0 = a et 1 = b
{
	size_t	size;
	int		i;

	size = 0;
	i = 0;
	if (witch == 0)
	{
		while (i < argc)
		{
			if ((*stack_a)[size] != (long) INT_MAX + 1)
				size++;
			i++;
		}
		return (size);
	}
	if (witch == 1)
	{
		while (i < argc)
		{
			if ((*stack_b)[size] != (long) INT_MAX + 1)
				size++;
			i++;
		}
		return (size);
	}
	return (-1);
}

int	main(int argc, char *argv[])
{
	int	long	*stack_a;
	int	long	*stack_b;
	int		i = 0;
	int		test = 0;
	
	argc--;
	init_stack(argc, argv, &stack_a, &stack_b);
	while (i < argc)
	{
		printf("%ld   %ld\n", stack_a[i], stack_b[i]);
		i++;
	}
	ft_push_pb(stack_a, stack_b, argc);
	ft_push_pb(stack_a, stack_b, argc);
	while (test < 1) //combien d'instruction
	{
		// printf("\n%d\n\n", size(argc, &stack_a, &stack_b, 0));
		// ft_swap(stack_a, stack_b, "sa");
		printf("\n%s\n",ft_reverse_rotate_rrr(stack_a, stack_b, argc));
		i = 0;
		while (i < argc)
		{
			printf("< %ld | %ld >\n", stack_a[i], stack_b[i]);
			i++;
		}
		test++;
	}
	free(stack_a);
	free(stack_b);
	return (0);
}
