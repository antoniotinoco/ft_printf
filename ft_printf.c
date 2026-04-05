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

/* int main(void)
{
	int ret1, ret2;
	char *null_str = NULL;
	void *null_ptr = NULL;
	
	printf("\n=== NO SPECIFIER TEST ===\n");
	ret1 = printf("[Hello, 42]\n");
	ret2 = ft_printf("[Hello, 42]\n");
	printf("Returns: %d vs %d\n\n", ret1, ret2);

	printf("=== CHARACTER TEST ===\n");
	ret1 = printf("[%c]\n", 'A');
	ret2 = ft_printf("[%c]\n", 'A');
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	printf("=== STRING TESTS ===\n");
	ret1 = printf("[%s]\n", "Hello, 42!");
	ret2 = ft_printf("[%s]\n", "Hello, 42!");
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%s]\n", null_str);
	ret2 = ft_printf("[%s]\n", null_str);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%s]\n", "");
	ret2 = ft_printf("[%s]\n", "");
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	printf("=== DECIMAL TESTS ===\n");
	ret1 = printf("[%d]\n", 42);
	ret2 = ft_printf("[%d]\n", 42);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%d]\n", -42);
	ret2 = ft_printf("[%d]\n", -42);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%d]\n", 0);
	ret2 = ft_printf("[%d]\n", 0);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%d]\n", INT_MIN);
	ret2 = ft_printf("[%d]\n", INT_MIN);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%d]\n", INT_MAX);
	ret2 = ft_printf("[%d]\n", INT_MAX);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	printf("=== INTEGER TESTS ===\n");
	ret1 = printf("[%i]\n", 123);
	ret2 = ft_printf("[%i]\n", 123);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%i]\n", -456);
	ret2 = ft_printf("[%i]\n", -456);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	printf("=== UNSIGNED TESTS ===\n");
	ret1 = printf("[%u]\n", 42);
	ret2 = ft_printf("[%u]\n", 42);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%u]\n", 0);
	ret2 = ft_printf("[%u]\n", 0);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%u]\n", UINT_MAX);
	ret2 = ft_printf("[%u]\n", UINT_MAX);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	printf("=== HEX LOWERCASE TESTS ===\n");
	ret1 = printf("[%x]\n", 42);
	ret2 = ft_printf("[%x]\n", 42);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%x]\n", 255);
	ret2 = ft_printf("[%x]\n", 255);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%x]\n", 0);
	ret2 = ft_printf("[%x]\n", 0);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%x]\n", UINT_MAX);
	ret2 = ft_printf("[%x]\n", UINT_MAX);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	printf("=== HEX UPPERCASE TESTS ===\n");
	ret1 = printf("[%X]\n", 42);
	ret2 = ft_printf("[%X]\n", 42);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%X]\n", 255);
	ret2 = ft_printf("[%X]\n", 255);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%X]\n", 0);
	ret2 = ft_printf("[%X]\n", 0);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	printf("=== POINTER TESTS ===\n");
	ret1 = printf("[%p]\n", (void *)0x7fff5fbff8a0);
	ret2 = ft_printf("[%p]\n", (void *)0x7fff5fbff8a0);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%p]\n", null_ptr);
	ret2 = ft_printf("[%p]\n", null_ptr);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%p]\n", &ret1);
	ret2 = ft_printf("[%p]\n", &ret1);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	printf("=== PERCENT TESTS ===\n");
	ret1 = printf("[%%]\n");
	ret2 = ft_printf("[%%]\n");
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[100%%]\n");
	ret2 = ft_printf("[100%%]\n");
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%%%%]\n");
	ret2 = ft_printf("[%%%%]\n");
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	printf("=== MIXED TESTS ===\n");
	ret1 = printf("[%s %d %c %x]\n", "Test", 42, '!', 255);
	ret2 = ft_printf("[%s %d %c %x]\n", "Test", 42, '!', 255);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%c%c%c]\n", 'A', 'B', 'C');
	ret2 = ft_printf("[%c%c%c]\n", 'A', 'B', 'C');
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	ret1 = printf("[%d%d%d]\n", 1, 2, 3);
	ret2 = ft_printf("[%d%d%d]\n", 1, 2, 3);
	printf("Returns: %d vs %d\n\n", ret1, ret2);
	
	printf("=== EDGE CASES (ft_printf only) ===\n");
	// These won't compile with the original printf due to warnings/errors
	ft_printf("[Test %]\n");
	ft_printf("[Invalid: %z]\n", 42);
	
	return (0);
} */
