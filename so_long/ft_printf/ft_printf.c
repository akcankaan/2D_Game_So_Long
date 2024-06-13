/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehakcan <mehakcan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:17:45 by mehakcan          #+#    #+#             */
/*   Updated: 2024/01/25 12:17:45 by mehakcan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_check(char str)
{
	return (str == 's' || str == 'c' || str == 'd' || str == 'i' || str == 'u'
		|| str == 'x' || str == 'X' || str == 'p' || str == '%');
}

static int	ft_format(va_list *arg, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg((*arg), int)));
	else if (format == 's')
		return (ft_string(va_arg((*arg), char *)));
	else if (format == 'p')
		return (ft_point(va_arg((*arg), unsigned long), 1));
	else if (format == 'd' || format == 'i')
		return (ft_int(va_arg((*arg), int)));
	else if (format == 'u')
		return (ft_unsigned(va_arg((*arg), int)));
	else if (format == 'X' || format == 'x')
		return (ft_hex(va_arg((*arg), unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	int		value;
	va_list	arg;

	i = -1;
	len = 0;
	va_start(arg, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%' && ft_check(format[i + 1]))
			value = ft_format(&arg, format[++i]);
		else if (format[i] != '%')
			value = ft_putchar(format[i]);
		if (value == -1)
			return (-1);
		len += value;
		value = 0;
	}
	va_end(arg);
	return (len);
}
