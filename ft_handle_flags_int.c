/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:51:24 by iouali            #+#    #+#             */
/*   Updated: 2021/01/27 14:21:18 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handle_flags_int(char *flags, int len, int after, long long nb)
{
	int	precision;
	int	width;
	int zeros;
	int	print_after;
	int	size;

	size = 0;
	precision = get_precision(flags);
	// printf("\nprecision: %d\n", precision);
	width = get_width(flags);
	zeros = get_zeros(flags, precision);
	print_after = get_print_after(flags, zeros, len, width, precision);
	// printf("\nwidth: %d / precisionß: %d / zeros: %d / print_after: %d, after: %d / len: %d / nb: %lld\n", width, precision, zeros, print_after, after, len, nb);
	if (precision > 0 && nb < 0)
		precision++;
	if (width <= len && precision <= len)
		return (-2);
	if (precision == -1 && zeros > 0)
			return (print_zeros(width, precision, len, nb, zeros));
	if (after == 1)
		return (print_spaces(width, precision, len, nb));
	if (width > len || precision > len)
	{
		if (print_after == 0)
			size += print_spaces(width, precision, len, nb);
		size += print_zeros(width, precision, len, nb, zeros);
	}
	if (print_after == 1 && after == 0)
		return (-1);
	// printf("\nsize: %d\n", size);
	return (size);
}

int		print_spaces(int width, int precision, int len, long long nb)
{
	int i;
	int max;
	int negative;

	i = 0;
	max = 0;
	negative = 0;
	// if (nb < 0)
	// 	negative = 1;
	if (nb == 0 && precision == 0)
		len--;
	if (width > len && precision >= width)
		max = 0;
	else if (precision > len && width > precision)
		max = width - precision - negative;
	else if (width > len && precision <= len)
		max = width - len;
	// printf("\nwidth: %d / len: %d / nb: %d\n", width, len, nb);
	// printf("\nmax for spaces: %d\n", max);
	while (i < max)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		print_zeros(int width, int precision, int len, long long nb, int zeros)
{
	int i;
	int max;

	i = 0;
	max = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		// if (zeros == 0)
		// 	len--;
	}
	// printf("\nlen: %d\n", len);
	if (zeros == 1)
		max = width - len;
	if (precision > len)
		max = precision - len;
	while (i < max)
	{
		write(1, "0", 1);
		i++;
	}
	if (!(nb == 0 && precision == 0))
		ft_putnbr(nb, precision);
	if (nb == '%')
		write(1, &nb, 1);
	// printf("\ni print_zeros: %d\n", i);
	return (i);
}
