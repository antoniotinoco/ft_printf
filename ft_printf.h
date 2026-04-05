/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atinoco- <atinoco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:37:02 by atinoco-          #+#    #+#             */
/*   Updated: 2025/11/09 11:37:02 by atinoco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(const char *str, ...);

int		ft_putchar(char c);
int		ft_putstr(const char *str);
char	*ft_strchr(const char *s, int c);

int		ft_putnbr_di(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbr_hex(unsigned long n, char c);
int		ft_putptr(void *ptr);

#endif
