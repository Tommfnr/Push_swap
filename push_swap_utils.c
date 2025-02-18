/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:44 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/18 21:41:05 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isnumber(const char *str) 
{
    int     i;
    int     num;

    i = 0;
    num = ft_atoi(str);
    if (str[i] == '-' || str[i] == '+')
    i++;
    if (str[i] == '\0' || num < INT_MIN || num > INT_MAX)
        return 0;
    while (str[i] != '\0') 
    {
        if (!ft_isdigit(str[i])) 
            return 0;
        i++;
    }
    return 1;
}

int ft_check_doublon(int argc, char **argv)
{
    int     i;
    int     j;
    
    i = 1;
    while (i < argc)
    {
        j = i + 1;
        while (j < argc)
        {
            if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

char    *ft_check_error(int argc, char **argv)
{
    int     i;

    i = 1;
    if (argc <= 1)
        return (NULL);
    while (i < argc)
    {
        if (ft_isnumber(argv[i]) == 0)
        {
            ft_printf("Error\n");
            return (NULL);
        }
        i++;
    }
    if (ft_check_doublon(argc, argv) == 0)
    {
        ft_printf("Error\n");
        return (NULL);
    }
    return ("valid");
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

int		ft_init_stack(int argc, char **argv, int long **stack_a, int long **stack_b)//recup la chaine et creer la stack_b calcule taille et regarde les erreurs
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

int	*ft_tri(int *stack_a, int len)//pour tester si la liste est trie
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