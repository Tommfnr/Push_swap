/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:10:51 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/18 21:26:01 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <limits.h>

#include "ft_printf.h"
#include "libft.h"

int		*ft_tri(int *stack_a, int len);

char 	*ft_swap_ab(int long *stack_a, int long *stack_b, int inst);
char 	*ft_swap_ss(int long *stack_a, int long *stack_b);
char	*ft_push_pa(int long *stack_a, int long *stack_b, int argc);
char	*ft_push_pb(int long *stack_a, int long *stack_b, int argc);
char	*ft_rotate_ab(int long *stack_a, int long *stack_b, int argc, int inst);
char    *ft_rotate_rr(int long *stack_a, int long *stack_b, int argc);
char	*ft_reverse_rotate_ab(int long *stack_a, int long *stack_b, int argc, char *inst);
char    *ft_reverse_rotate_rrr(int long *stack_a, int long *stack_b, int argc);

char    *ft_check_error(int argc, char **argv);
int 	ft_check_doublon(int argc, char **argv);
int 	ft_isnumber(const char *str);
int		ft_size(int argc, int long **stack_a, int long **stack_b, int witch);
int		ft_init_stack(int argc, char **argv, int long **stack_a, int long **stack_b);

#endif