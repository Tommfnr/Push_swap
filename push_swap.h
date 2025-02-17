/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:10:51 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/17 17:42:54 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>

#include "ft_printf.h"
#include "libft.h"

//int	*ft_tri(int *stack_a, int len);

char	*ft_swap(int *stack_a, int *stack_b, char *inst);
// char	*ft_push(int *stack_a,char *inst);
// char	*ft_rotate(int *stack_a,char *inst);
// char	*ft_reverse(int *stack_a,char *inst);

#endif