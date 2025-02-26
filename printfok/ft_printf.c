/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:37:38 by tfournie          #+#    #+#             */
/*   Updated: 2025/01/29 16:33:23 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	// -1
	return (write(1, &c, 1));
}

static int	handle_conversion(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_put_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_put_hex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_put_hex(va_arg(args, unsigned int), 1));
	else if (c == 'p')
		return (ft_put_pointer(va_arg(args, void *)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed;

	if (format == NULL)
		return (-1);
	i = 0;
	printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])// tester les convertions
		{
			printed += handle_conversion(format[i + 1], args);
			i++;
		}
		else
			printed += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (printed);
}

//a corriger;

// int main(void)
// {
//     int nbchars;
//     int print_nbchars;
// 	int	*p;

// 	p = NULL;
//     // Test with simple string
// 	printf("ft : \n");
//     nbchars = ft_printf("%");
// 	printf("\n");
// 	printf("printf :\n");
//     print_nbchars = printf("%");
//     printf("\n%d", nbchars);
//     printf("\n%d", print_nbchars);

//     return 0;
// }
