/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:33:17 by iouali            #+#    #+#             */
/*   Updated: 2021/01/21 12:57:33 by iouali           ###   ########.fr       */
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
		len += ft_handle_flags_int(flags, len, 1, nb);
	else
		len += decision;
	// printf("\n|handle_int len: %d|\n", len);
	return (len);
}
