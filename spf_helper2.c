/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spf_helper2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atinoco- <atinoco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:05:52 by atinoco-          #+#    #+#             */
/*   Updated: 2025/11/12 22:05:52 by atinoco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_di(int n)
{
	int		count;
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_di(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putnbr_u(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_u(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putnbr_hex(unsigned long n, char c)
{
	int		count;
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, c);
	write(1, &hex[n % 16], 1);
	count++;
	return (count);
}

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	addr;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	addr = (unsigned long)ptr;
	count += ft_putnbr_hex(addr, 'x');
	return (count);
}
