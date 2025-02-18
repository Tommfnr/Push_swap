/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:10:51 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/18 19:56:52 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <limits.h>

#include "ft_printf.h"
#include "libft.h"

int	*ft_tri(int *stack_a, int len);


char	*ft_swap(int long *stack_a, int long *stack_b, char *inst);
char	*ft_push_pa(int long *stack_a, int long *stack_b, int argc);
char	*ft_push_pb(int long *stack_a, int long *stack_b, int argc);
char	*ft_rotate_ab(int long *stack_a, int long *stack_b, int argc, char *inst);
char    *ft_rotate_rr(int long *stack_a, int long *stack_b, int argc);
char	*ft_reverse_rotate_ab(int long *stack_a, int long *stack_b, int argc, char *inst);
char    *ft_reverse_rotate_rrr(int long *stack_a, int long *stack_b, int argc);

int	ft_size(int argc, int long **stack_a, int long **stack_b, int witch);

#endif