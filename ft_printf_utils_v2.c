/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_v2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:40:41 by iouali            #+#    #+#             */
/*   Updated: 2021/01/28 14:01:21 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*replace_with_star(char *orig, int n, int len)
{
	char			*result;
	char			*star;
	unsigned long	i;
	int				j;

	if (!(star = ft_itoa(n)))
		return (NULL);
	if (!(result = malloc(sizeof(char) * (ft_strlen(star) + len + 1))))
		return (NULL);
	ft_bzero(result, ft_strlen(star) + len);
	i = 0;
	while (orig[i])
	{
		result[i] = orig[i];
		i++;
	}
	j = 0;
	while (star[j])
	{
		result[i] = star[j];
		i++;
		j++;
	}
	while (i <= ft_strlen(star) + len)
	{
		result[i] = '\0';
		i++;
	}
	free(orig);
	free(star);
	return (result);
}

int		print_str_len(char *str, int max)
{
	int i;

	i = 0;
	while (i < max && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
