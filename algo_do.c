/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_do.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:33:52 by tfournie          #+#    #+#             */
/*   Updated: 2025/02/27 20:10:57 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_aup_bup(long *stack_a, long *stack_b, int argc, long element)
{
	int	i;
	int	nb_inst_aup;
	int	nb_inst_bup;

	nb_inst_aup = ft_find_good_place_aup(stack_a, stack_b, argc, element);
	nb_inst_bup = ft_find_good_place_bup(stack_a, stack_b, argc, element);
	i = 0;
	if (nb_inst_aup > nb_inst_bup)
	{
		while (i < nb_inst_bup)
		{
			ft_rotate_rr(stack_a, stack_b, argc);
			i++;
		}
		while (i < nb_inst_aup)
		{
			ft_rotate_ab(stack_a, stack_b, argc, 0);
			i++;
		}
	}
	else if (nb_inst_aup < nb_inst_bup)
	{
		while (i < nb_inst_aup)
		{
			ft_rotate_rr(stack_a, stack_b, argc);
			i++;
		}
		while (i < nb_inst_bup)
		{
			ft_rotate_ab(stack_a, stack_b, argc, 1);
			i++;
		}
	}
	else
	{
		while (i < nb_inst_aup)
		{
			ft_rotate_rr(stack_a, stack_b, argc);
			i++;
		}
	}
}

void	ft_do_aup_bdown(long *stack_a, long *stack_b, int argc, long element)
{
	int	i;
	int	nb_inst_aup;
	int	nb_inst_bdown;

	nb_inst_aup = ft_find_good_place_aup(stack_a, stack_b, argc, element);
	nb_inst_bdown = ft_find_good_place_bdown(stack_a, stack_b, argc, element);
	i = 0;
	while (i < nb_inst_aup)
	{
		ft_rotate_ab(stack_a, stack_b, argc, 0);
		i++;
	}
	i = 0;
	while (i < nb_inst_bdown)
	{
		ft_reverse_rotate_ab(stack_a, stack_b, argc, 1);
		i++;
	}
}

void	ft_do_adown_bup(long *stack_a, long *stack_b, int argc, long element)
{
	int	i;
	int	nb_inst_adown;
	int	nb_inst_bup;

	nb_inst_adown = ft_find_good_place_adown(stack_a, stack_b, argc, element);
	nb_inst_bup = ft_find_good_place_bup(stack_a, stack_b, argc, element);
	i = 0;
	while (i < nb_inst_adown)
	{
		ft_reverse_rotate_ab(stack_a, stack_b, argc, 0);
		i++;
	}
	i = 0;
	while (i < nb_inst_bup)
	{
		ft_rotate_ab(stack_a, stack_b, argc, 1);
		i++;
	}
}

void	ft_do_adown_bdown(long *stack_a, long *stack_b, int argc, long element)
{
	int	i;
	int	nb_inst_adown;
	int	nb_inst_bdown;

	nb_inst_adown = ft_find_good_place_adown(stack_a, stack_b, argc, element);
	nb_inst_bdown = ft_find_good_place_bdown(stack_a, stack_b, argc, element);
	i = 0;
	if (nb_inst_adown > nb_inst_bdown)
	{
		while (i < nb_inst_bdown)
		{
			ft_reverse_rotate_rrr(stack_a, stack_b, argc);
			i++;
		}
		while (i < nb_inst_adown)
		{
			ft_reverse_rotate_ab(stack_a, stack_b, argc, 0);
			i++;
		}
	}
	else if (nb_inst_adown < nb_inst_bdown)
	{
		while (i < nb_inst_adown)
		{
			ft_reverse_rotate_rrr(stack_a, stack_b, argc);
			i++;
		}
		while (i < nb_inst_bdown)
		{
			ft_reverse_rotate_ab(stack_a, stack_b, argc, 1);
			i++;
		}
	}
	else
	{
		while (i < nb_inst_adown)
		{
			ft_reverse_rotate_rrr(stack_a, stack_b, argc);
			i++;
		}
	}
}
