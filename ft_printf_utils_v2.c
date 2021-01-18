/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_v2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:40:41 by iouali            #+#    #+#             */
/*   Updated: 2021/01/14 16:45:28 by iouali           ###   ########.fr       */
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
	// printf("\nstar: %s\n", star);
	// printf("\norig: %s\n", orig);
	while (orig[i])
	{
		result[i] = orig[i];
		i++;
	}
	j = 0;
	// printf("\ni avant: %lu\n", i);
	while (star[j])
	{
		result[i] = star[j];
		i++;
		j++;
	}
	// printf("\ni apres: %lu\n", i);
	while (i <= ft_strlen(star) + len)
	{
		result[i] = '\0';
		i++;
	}
	// result[i] = '\0';
	// printf("\nresult: %s/ i: %lu / longueur star: %lu / longueur len: %d\n", result, i, ft_strlen(star), len);
	free(orig);
	free(star);
	return (result);
}