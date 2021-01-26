/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags_hexa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:31:42 by iouali            #+#    #+#             */
/*   Updated: 2021/01/22 13:22:57 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handle_flags_hexa(char *flags, int *tab, int after, long long nb)
{
	int	precision;
	int	width;
	int zeros;
	int	print_after;
	int	size;

	// printf("\n nb hexa: %lld\n", nb);
	size = 0;
	precision = get_precision(flags);
	width = get_width(flags);
	zeros = get_zeros(flags, precision);
	print_after = get_print_after(flags, zeros, 0, width, precision);
	// printf("\nwidth: %d / precisionß: %d / zeros: %d / print_after: %d, after: %d / len: %d / nb: %lld\n", width, precision, zeros, print_after, after, tab[0], nb);
	if (width <= tab[0] && precision <= tab[0] && !(precision == 0 && nb == 0))
		return (-2);
	if (precision == -1 && zeros > 0)
		return (print_zeros_hexa(width, precision, tab, nb, zeros));
	if (after == 1)
		return (print_spaces_hexa(width, precision, tab[0], nb));
	if (width > tab[0] || precision > tab[0])
	{
		if (print_after == 0)
		{
			size += print_spaces_hexa(width, precision, tab[0], nb);
			if (tab[1] == 'p')
				ft_putstr("0x");
		}
		size += print_zeros_hexa(width, precision, tab, nb, zeros);
	}
	if (print_after == 1 && after == 0)
		return (-1);
	return (size);
}

int		print_spaces_hexa(int width, int precision, int len, long long nb)
{
	int i;
	int max;
	int negative;

	i = 0;
	max = 0;
	negative = 0;
	if (nb < 0)
		negative = 1;
	if (nb == 0 && precision == 0)
		len--;
	if (width > len && precision >= width)
		max = 0;
	else if (precision > len && width > precision)
		max = width - precision - negative;
	else if (width > len && precision <= len)
		max = width - len;
	while (i < max)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		print_zeros_hexa(int width, int precision, int *tab, long long nb, int zeros)
{
	int i;
	int max;
	int len;

	len = tab[0];
	i = 0;
	max = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		if (zeros == 0)
			len--;
	}
	if (zeros == 1)
		max = width - len;
	if (precision > len)
		max = precision - len;
	while (i < max)
	{
		write(1, "0", 1);
		i++;
	}
	// printf("HEEEEEYYYY");
	if (!(nb == 0 && precision == 0))
		write_to_hexa(nb, tab[1]);
	return (i);
}
