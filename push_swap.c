/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:38 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/17 18:03:27 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		init_stack(int len_a, char **lst,int **stack_a,int **stack_b)//recup la chaine et creer la stack_b calcule taille et regarde les erreurs
{
	int		i;

	i = 1;
	*stack_a = malloc((len_a - 1) * sizeof(int));
	if (!*stack_a)
		return (-1);
	*stack_b = malloc((len_a - 1) * sizeof(int));
	if (!*stack_a)
	{
		free(stack_a);
		return (-1);
	}
	while (i < len_a)
	{
		(*stack_a)[i - 1] = ft_atoi(lst[i]);
		ft_printf("%d\n",(*stack_a)[i - 1]);
		i++;
	}
	// stack_b = {0};
	return (len_a - 1);
}

int	main(int argc, char *argv[])
{
	int		*stack_a;
	int		*stack_b;
	int		len_a;
	int		i = 0;
	
	len_a = init_stack(argc, argv, &stack_a, &stack_b);
	ft_printf("\n");
	ft_swap(stack_a, stack_b, "sa");
	while (i < len_a)
	{
		ft_printf("%d\n", stack_a[i]);
		i++;
	}
	free(stack_a);
	free(stack_b);
	return (0);
}


// int	main(void)
// {
// 	int		list[] = {12,55,44,468,1,20,5,-2};
// 	int		i = 0;
// 	int		len = sizeof(list)/sizeof(int);
// 	//ft_tri(list, len);
	
// 	while (i < len)
// 	{
// 		ft_printf("trier: %d\n",list[i]);
// 		i++;
// 	}
// 	return (0);	
// }