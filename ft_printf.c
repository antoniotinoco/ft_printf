/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atinoco- <atinoco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:37:26 by atinoco-          #+#    #+#             */
/*   Updated: 2025/11/09 11:37:26 by atinoco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_spf(const char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_di(va_arg(ap, int));
	else if (c == 'u')
		count += ft_putnbr_u(va_arg(ap, unsigned int));
	else if (c == 'x')
		count += ft_putnbr_hex((unsigned long)va_arg(ap, unsigned int), 'x');
	else if (c == 'X')
		count += ft_putnbr_hex((unsigned long)va_arg(ap, unsigned int), 'X');
	else if (c == 'p')
		count += ft_putptr(va_arg(ap, void *));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			if (ft_strchr("cspdiuxX%", str[i + 1]))
			{
				count += print_spf(str[i + 1], ap);
				i++;
			}
			else
				count += ft_putchar(str[i]);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
