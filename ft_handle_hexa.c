/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:49:42 by iouali            #+#    #+#             */
/*   Updated: 2021/01/12 17:25:18 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handle_hexa(long long nb, char *flags, char op)
{
	int			len;
	int			decision;
	long long	n;
	int			tab[2];

	len = 0;
	n = nb;
	tab[1] = op;
	if (n < 0)
		n = -n;
	if (op == 'p')
		len += 2;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	if (nb <= 0)
		len++;
	tab[0] = len;
	decision = ft_handle_flags_hexa(flags, tab, 0, nb);
	if (decision == -2)
		write_to_hexa(nb, tab[1]);
	else if (decision == -1)
		len += ft_handle_flags_hexa(flags, tab, 1, nb);
	else
		len += decision;
	return (len);
}
