/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:42:43 by tfournie          #+#    #+#             */
/*   Updated: 2025/01/28 15:13:33 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr(int n)
{
	int	printed;

	printed = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		printed += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		printed += ft_putnbr(n / 10);
	printed += ft_putchar(n % 10 + '0');
	return (printed);
}

int	ft_put_unsigned(unsigned int n)
{
	int	printed;

	printed = 0;
	if (n >= 10)
		printed += ft_put_unsigned(n / 10);
	printed += ft_putchar(n % 10 + '0');
	return (printed);
}

int	ft_put_hex(unsigned long n, int uppercase)
{
	char	*hex;

	if (n == 0)
		return (ft_putchar('0'));
	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		return (ft_put_hex(n / 16, uppercase) + ft_putchar(hex[n % 16]));
	return (ft_putchar(hex[n]));
}

int	ft_put_pointer(void *ptr)
{
	unsigned long	addr;
	int				printed;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	addr = (unsigned long)ptr;
	printed = 0;
	printed += ft_putstr("0x");
	if (!addr)
		printed += ft_putchar('0');
	else
		printed += ft_put_hex(addr, 0);
	return (printed);
}
