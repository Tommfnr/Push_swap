/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:10:51 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/26 10:41:56 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <limits.h>

#include <stdio.h>

#include "ft_printf.h"
#include "libft.h"

int		*ft_sort(long *stack_a, int argc);
int		ft_stack_sorted(long *stack_a, int argc);

void	ft_algo_sort(long *stack_a, long *stack_b, int argc);
void 	ft_sort_three(long *stack_a, long *stack_b, int argc, int witch);
void 	ft_push_min_a(long *stack_a, long *stack_b, int argc);
void 	ft_sort_four(long *stack_a, long *stack_b, int argc);
void 	ft_sort_five(long *stack_a, long *stack_b, int argc);

long	*ft_find_indx_max_a(long *stack_a, long *stack_b, int argc);
long	*ft_find_indx_max_b(long *stack_a, long *stack_b, int argc);
long	*ft_find_indx_min_a(long *stack_a, long *stack_b, int argc);
long	*ft_find_indx_min_b(long *stack_a, long *stack_b, int argc);

char 	*ft_swap_ab(long *stack_a, long *stack_b, int inst);
char 	*ft_swap_ss(long *stack_a, long *stack_b);
char	*ft_push_pa(long *stack_a, long *stack_b, int argc);
char	*ft_push_pb(long *stack_a, long *stack_b, int argc);
char	*ft_rotate_ab(long *stack_a, long *stack_b, int argc, int inst);
char    *ft_rotate_rr(long *stack_a, long *stack_b, int argc);
char	*ft_reverse_rotate_ab(long *stack_a, long *stack_b, int argc, int inst);
char    *ft_reverse_rotate_rrr(long *stack_a, long *stack_b, int argc);

char    *ft_check_error(int argc, char **argv);
int 	ft_check_doublon(int argc, char **argv);
int 	ft_isnumber(const char *str);
int		ft_size(int argc, long **stack_a, long **stack_b, int witch);
int		ft_init_stack(int argc, char **argv, long **stack_a, long **stack_b);


//algo

long	ft_find_min_cost(long **array_cost, int size_a);
int		ft_col_min_cost(long **array_cost, int size_a, int element);
int		ft_line_min_cost(long **array_cost, int size_a, int element);
void	ft_processe_min_cost(long *stack_a, long *stack_b, int argc, long **array_cost);
void	ft_exe_algo(long *stack_a, long *stack_b, int argc);


//algo_cost_ab

int		ft_countc_aup_bup(long *stack_a, long *stack_b, int argc, long element);
int		ft_countc_aup_bdown(long *stack_a, long *stack_b, int argc, long element);
int		ft_countc_adown_bup(long *stack_a, long *stack_b, int argc, long element);
int		ft_countc_adown_bdown(long *stack_a, long *stack_b, int argc, long element);


//algo_cost_ab_utils

long	ft_find_max_b(long *stack_a, long *stack_b, int argc);
int 	ft_find_good_place_aup(long *stack_a, long *stack_b, int argc, long element);
int 	ft_find_good_place_adown(long *stack_a, long *stack_b, int argc, long element);
int 	ft_find_good_place_bup(long *stack_a, long *stack_b, int argc, long element);
int 	ft_find_good_place_bdown(long *stack_a, long *stack_b, int argc, long element);


//algo_cost

void	ft_count_cost_element(long *stack_a, long *stack_b, int argc, long **array_cost);
void	ft_free_array(long *stack_a, long *stack_b, int argc, long **array_cost);
long	**ft_init_array_cost(long *stack_a, long *stack_b, int argc);


//algo_do

void	ft_do_aup_bup(long *stack_a, long *stack_b, int argc, long element);
void	ft_do_aup_bdown(long *stack_a, long *stack_b, int argc, long element);
void	ft_do_adown_bup(long *stack_a, long *stack_b, int argc, long element);
void	ft_do_adown_bdown(long *stack_a, long *stack_b, int argc, long element);

#endif