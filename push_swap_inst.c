/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:49 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/18 19:58:06 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//inst = instuction

//sa , sb , ss = ft_swap
char *ft_swap(int long *stack_a, int long *stack_b, char *inst)
{
    int temp;

    if (strncmp(inst, "sa", 2) == 0)
    {
        if (stack_a && stack_a[1] != 0) { // Vérifier que stack_a contient au moins 2 éléments
            temp = stack_a[0];
            stack_a[0] = stack_a[1];
            stack_a[1] = temp;
        }
        return ("sa");
    }
    if (strncmp(inst, "sb", 2) == 0)
    {
        if (stack_b && stack_b[1] != 0)// Vérifier que stack_b contient au moins 2 éléments
        { 
            temp = stack_b[0];
            stack_b[0] = stack_b[1];
            stack_b[1] = temp;
        }
        return ("sb");
    }
    if (strncmp(inst, "ss", 2) == 0)
    {
        if (stack_a && stack_a[1] != 0)// Vérifier que stack_a contient au moins 2 éléments
        {
            temp = stack_a[0];
            stack_a[0] = stack_a[1];
            stack_a[1] = temp;
        }
        if (stack_b && stack_b[1] != 0)// Vérifier que stack_b contient au moins 2 éléments
        {
            temp = stack_b[0];
            stack_b[0] = stack_b[1];
            stack_b[1] = temp;
        }
        return ("ss");
    }
    return (NULL);
}

//pa , pb = ft_push
char	*ft_push_pa(int long *stack_a, int long *stack_b, int argc)
{
    int long    temp;
    int     i;
    int     size_a;
    int     size_b;

    i = 0;
    if (stack_b)// Vérifier que stack_b n'est pas vide
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
        stack_b[0] = (long) INT_MAX + 1;
        i = 0;
        while (i < size_b)
        {
            temp = stack_b[i + 1];
            stack_b[i + 1] = stack_b[i];
            stack_b[i] = temp;
            i++;
        }
        stack_b[size_b - 1] = (long) INT_MAX + 1;
        return ("pb");
    }
    return NULL;
}

char	*ft_push_pb(int long *stack_a, int long *stack_b, int argc)
{
    int long    temp;
    int     i;
    int     size_a;
    int     size_b;

    i = 0;
    if (stack_a)// Vérifier que stack_a n'est pas vide
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
        stack_a[0] = (long) INT_MAX + 1;
        i = 0;
        while (i < size_a)
        {
            temp = stack_a[i + 1];
            stack_a[i + 1] = stack_a[i];
            stack_a[i] = temp;
            i++;
        }
        stack_a[size_a - 1] = (long) INT_MAX + 1;
        return ("pb");
    }
    return NULL;
}

//ra , rb , rr= ft_rotate
char	*ft_rotate_ab(int long *stack_a, int long *stack_b, int argc, char *inst)
{
    int long    temp;
    int         i;
    int         size_a;
    int         size_b;
    
    i = 0;
    size_a = ft_size(argc, &stack_a, &stack_b, 0);
    size_b = ft_size(argc, &stack_a, &stack_b, 1);
    if (strncmp(inst, "ra", 2) == 0 && stack_a && stack_a[1] != 0)
    {
        temp = stack_a[0];
        while (i < size_a)
        {
            stack_a[i] = stack_a[i + 1];
            i++;
        }
        stack_a[size_a - 1] = temp;
        return ("ra");
    }
    if (strncmp(inst, "rb", 2) == 0 && stack_b && stack_b[1] != 0)
    {
        temp = stack_b[0];
        while (i < size_b)
        {
            stack_b[i] = stack_b[i + 1];
            i++;
        }
        stack_b[size_b - 1] = temp;
        return ("rb");
    }
    return (NULL);
}

char    *ft_rotate_rr(int long *stack_a, int long *stack_b, int argc)
{
    int long    temp;
    int         i;
    int         size_a;
    int         size_b;
    
    i = 0;
    size_a = ft_size(argc, &stack_a, &stack_b, 0);
    size_b = ft_size(argc, &stack_a, &stack_b, 1);
    if (stack_a && stack_a[1] != 0 && stack_b && stack_b[1] != 0)
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
        while (i < size_b )
        {
            stack_b[i] = stack_b[i + 1];
            i++;
        }
        stack_b[size_b - 1] = temp;
        return ("rr");
    }
    return (NULL);    
}

//rra , rrb , rrr = ft_reverse
char	*ft_reverse_rotate_ab(int long *stack_a, int long *stack_b, int argc, char *inst)
{
    int long    temp;
    int         i;
    int         size_a;
    int         size_b;
    
    size_a = ft_size(argc, &stack_a, &stack_b, 0);
    size_b = ft_size(argc, &stack_a, &stack_b, 1);
    if (strncmp(inst, "rra", 3) == 0 && stack_a && stack_a[1] != 0)
    {
        i = size_a - 1;
        temp = stack_a[size_a - 1];
        while (i > 0)
        {
            stack_a[i] = stack_a[i - 1];
            i--;
        }
        stack_a[0] = temp;
        return ("rra");
    }
    if (strncmp(inst, "rrb", 3) == 0 && stack_b && stack_b[1] != 0)
    {
        i = size_b - 1;
        temp = stack_b[size_b - 1];
        while (i > 0)
        {
            stack_b[i] = stack_b[i - 1];
            i--;
        }
        stack_b[0] = temp;
        return ("rrb");
    }
    return (NULL);
}

char	*ft_reverse_rotate_rrr(int long *stack_a, int long *stack_b, int argc)
{
    int long    temp;
    int         i;
    int         size_a;
    int         size_b;
    
    size_a = ft_size(argc, &stack_a, &stack_b, 0);
    size_b = ft_size(argc, &stack_a, &stack_b, 1);
    if (stack_a && stack_a[1] != 0 && stack_b && stack_b[1] != 0)
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
        return ("rrr");
    }
    return (NULL);
}