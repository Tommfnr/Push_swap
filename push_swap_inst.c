/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:49 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/17 18:00:07 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa , sb , ss = ft_swap
//pa , pb = ft_push
//ra , rb , rr= ft_rotate
//rra , rrb , rrr = ft_reverse
//inst = instuction

#include <stdio.h> // Pour printf

#include <stdio.h>
#include <string.h> // Inclure la bibliothèque pour strcmp

char *ft_swap(int *stack_a, int *stack_b, char *inst)
{
    int temp;

    if (ft_strncmp(inst, "sa", 2) == 0) // Utiliser strcmp pour comparer les chaînes
    {
        if (stack_a && stack_a[1] != 0) { // Vérifier que stack_a contient au moins 2 éléments
            temp = stack_a[0];
            stack_a[0] = stack_a[1];
            stack_a[1] = temp;
        }
        return ("sa");
    }

    if (ft_strncmp(inst, "sb", 2) == 0) // Utiliser strcmp pour comparer les chaînes
    {
        if (stack_b && stack_b[1] != 0) { // Vérifier que stack_b contient au moins 2 éléments
            temp = stack_b[0];
            stack_b[0] = stack_b[1];
            stack_b[1] = temp;
        }
        return ("sb");
    }

    if (ft_strncmp(inst, "ss", 2) == 0) // Utiliser strcmp pour comparer les chaînes
    {
        if (stack_a && stack_a[1] != 0) { // Vérifier que stack_a contient au moins 2 éléments
            temp = stack_a[0];
            stack_a[0] = stack_a[1];
            stack_a[1] = temp;
        }
        if (stack_b && stack_b[1] != 0) { // Vérifier que stack_b contient au moins 2 éléments
            temp = stack_b[0];
            stack_b[0] = stack_b[1];
            stack_b[1] = temp;
        }
        return ("ss");
    }

    return NULL; // Si aucune instruction ne correspond
}


// char	*ft_push(int *stack_a,char *inst)

// char	*ft_rotate(int *stack_a,char *inst)

// char	*ft_reverse(int *stack_a,char *inst)
