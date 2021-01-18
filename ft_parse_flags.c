/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:59:01 by iouali            #+#    #+#             */
/*   Updated: 2021/01/14 17:42:06 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_precision(char *flags)
{
	int i;
	int result;

	result = -1;
	i = 0;
	while (flags[i])
	{
		if (flags[i] == '.')
		{	
			result = ft_atoi(&flags[++i]);
			if (result < 0)
				return (-1);
		}	
		i++;
	}
	return (result);
}

int	get_width(char *flags)
{
	int i;
	int result;

	i = 0;
	if (flags[i] == '-' || flags[i] == '0')
		i++;
	if (flags[i] == '-')
		i++;
	if (ft_isdigit(flags[i]))
		result = ft_atoi(&flags[i]);
	else
		result = -1;
	return (result);
}

int	get_zeros(char *flags, int precision)
{
	if (precision >= 0)
		return (0);
	if (flags[1] == '-')
		return (0);
	if (flags[0] == '0')
		return (1);
	return (0);
}

int	get_print_after(char *flags, int zeros, int len, int width, int precision)
{
	if (width <= len || width <= precision)
		return (0);
	if (flags[0] == '-')
		return (1);
	if (flags[0] == '0' && zeros == 0 && flags[1] == '-')
		return (1);
	return (0);
}
