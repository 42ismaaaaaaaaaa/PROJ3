/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:26:12 by iouali            #+#    #+#             */
/*   Updated: 2021/01/14 13:33:48 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putnbr(long long n, int precision)
{
	long long	mod;
	char		to_write;

	// if (n == -2147483648)
	// 	write(1, "-2147483648", 11);
	if (n == 0 && precision == 0)
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	mod = n % 10;
	n /= 10;
	if (n > 0)
		ft_putnbr(n, precision);
	to_write = mod + 48;
	write(1, &to_write, 1);
}

void	write_to_hexa(long long c, char op)
{
	char		hexa[17] = "0123456789abcdef";
	char		to_write;
	long long	mod;

	if (c < 0)
	{
		write(1, "-", 1);
		c *= -1;
	}
	mod = c % 16;
	c /= 16;
	if (c > 0)
		write_to_hexa(c, op);
	if (op == 'X' && mod > 9 && op != 'p')
		to_write = hexa[mod] - 32;
	else
		to_write = hexa[mod];
	write(1, &to_write, 1);
}
