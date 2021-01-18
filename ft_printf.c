/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:03:12 by iouali            #+#    #+#             */
/*   Updated: 2021/01/14 17:05:32 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_op(char c)
{
	char	op[9] = "diuscxXp\%";
	int		i;

	i = 0;
	while (op[i])
	{
		if (c == op[i])
			return (op[i]);
		i++;
	}
	return (0);
}

char	get_op(char *str)
{
	int i;

	i = 0;
	while (!is_op(str[i]))
		i++;
	return (is_op(str[i]));
}

char	*parse_flags(char *str, va_list params)
{
	char	*result;
	int		len;
	int		i;
	int		j;

	len = 0;
	while (!is_op(str[len]) && str[len])
		len++;
	if (!(result = malloc(sizeof(char) * len)))
		return (0);
	ft_bzero(result, len);
	i = 0;
	j = 0;
	while (!is_op(str[i]) && str[i])
	{
		if (str[i] == '*')
		{
			result = replace_with_star(result, va_arg(params, int), len);
			j = ft_strlen(result);
			// printf("\nj dans la boucle: %d\n", j);
			i++;
		}
		else		
		{
			result[j] = str[i];
			i++;
			j++;
		}
	}
	// printf("\nj: %d\n", j);
	// result[j] = '\0';
	// printf("\nflags: %s\n", result);
	return (result);
}

int		ft_handle_all(char *str, va_list params)
{
	int		len;
	char	*flags;
	char	op;

	flags = parse_flags(str, params);
	op = get_op(str);
	// printf("\nop: %c\n", op);
	len = 0;
	if (op == 'd' || op == 'i')
		len += ft_handle_int(va_arg(params, int), flags);
	if (op == 'u')
		len += ft_handle_int(va_arg(params, unsigned int), flags);
	if (op == 's')
		len += ft_handle_str(va_arg(params, char *), flags);
	if (op == 'c')
		len += ft_handle_char(va_arg(params, int), flags);
	if (op == 'x' || op == 'X')
		len += ft_handle_hexa(va_arg(params, unsigned int), flags, op);
	if (op == 'p')
		len += ft_handle_pointers(va_arg(params, void*), flags);
	if (op == '%')
		len += ft_handle_percent(flags);
	free(flags);
	// printf("\nhandle_all len: %d\n", len);
	return (len);
}

int		ft_printf(const char *str, ...)
{
	va_list params;
	int		i;
	int		len;
	int		printed;

	va_start(params, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		printed = 0;
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			len++;
		}
		else
		{
			printed = ft_handle_all((char *) &str[++i], params);
			while (!is_op(str[i]))
				i++;
		}
		len += printed;
		i++;
	}
	va_end(params);
	return (len);
}