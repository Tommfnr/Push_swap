/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:33:04 by tfournie          #+#    #+#             */
/*   Updated: 2025/03/03 17:39:32 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_isnumber(const char *str)
{
	int		i;
	long	num;

	i = 0;
	num = ft_atoi(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_check_error(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_isnumber(argv[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
		i++;
	}
	if (ft_check_duplicate(argc, argv) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	return ("valid");
}
