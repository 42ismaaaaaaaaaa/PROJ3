/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:33:17 by iouali            #+#    #+#             */
/*   Updated: 2021/01/26 17:10:31 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handle_int(long long nb, char *flags)
{
	int			len;
	int			decision;
	long long	n;

	len = 0;
	n = nb;
	// printf("\nflags: %s\n", flags);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	if (nb <= 0 && !(get_precision(flags) == 0 && nb == 0))
		len++;
	// printf("\n|handle_int len: %d|\n", len);
	decision = ft_handle_flags_int(flags, len, 0, nb);
	// printf("\ndecision: %d\n", decision);
	if (decision == -2 || decision == 0)
		ft_putnbr(nb, get_precision(flags));
	else if (decision == -1)
	{
		// len += ft_check_if_zeros(flags, len, nb);
		len += ft_handle_flags_int(flags, len, 1, nb);
	}
	else
		len += decision;
	// printf("\n|handle_int len: %d|\n", len);
	return (len);
}

int		ft_check_if_zeros(char *flags, int len, long long nb)
{
	int	precision;
	int	width;
	int zeros;
	int	size;
	int max;

	size = 0;
	max = 0;
	nb = 0;
	precision = get_precision(flags);
	// if (nb < 0)
	// 	precision++;
	width = get_width(flags);
	zeros = get_zeros(flags, precision);
	max = precision - len;
	// printf("\nprecision: %d / width: %d / zeros: %d / len: %d\n", precision, width, zeros, len);
	while (size < max)
		size++;
	// printf(" size: %d\n", size);
	return (size);
}
