/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:29:52 by iouali            #+#    #+#             */
/*   Updated: 2021/01/28 14:07:37 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handle_pointers(void *nb, char *flags)
{
	unsigned long	n;
	int				zeros;
	int				precision;
	int				print_after;
	int				width;

	precision = get_precision(flags);
	zeros = get_zeros(flags, precision);
	width = get_width(flags);
	print_after = get_print_after(flags, zeros, 0, precision);
	n = (unsigned long)nb;
	if (print_after == 1 || zeros == 1 ||
		ft_strlen(flags) == 0 || width <= size_of_hex(n) + 2)
		ft_putstr("0x");
	return (ft_handle_hexa((unsigned long)nb, flags, 'p'));
}

int		size_of_hex(long long nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}
