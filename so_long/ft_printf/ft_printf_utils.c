/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehakcan <mehakcan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:17:58 by mehakcan          #+#    #+#             */
/*   Updated: 2024/01/25 12:17:58 by mehakcan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_int(int nb)
{
	long	n;
	int		len;
	int		value;

	len = 0;
	n = nb;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n *= -1;
		len++;
	}
	if (n > 9)
	{
		value = ft_int(n / 10);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (write(1, &"0123456789"[n % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_unsigned(unsigned int number)
{
	int		len;
	int		value;
	char	*base;

	base = "0123456789";
	len = 0;
	if (number >= 10)
	{
		value = ft_unsigned(number / 10);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (ft_putchar(base[number % 10]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i])
		if (ft_putchar(str[i++]) == -1)
			return (-1);
	return (i);
}

int	ft_hex(unsigned int number, char format)
{
	int	len;
	int	value;

	len = 0;
	if (number >= 16)
	{
		value = ft_hex(number / 16, format);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (format == 'X')
	{
		if (ft_putchar("0123456789ABCDEF"[number % 16]) == -1)
			return (-1);
	}
	if (format == 'x')
	{
		if (ft_putchar("0123456789abcdef"[number % 16]) == -1)
			return (-1);
	}
	return (len + 1);
}

int	ft_point(unsigned long int number, int mod)
{
	int	len;
	int	value;

	len = 0;
	if (mod == 1)
	{
		if (ft_string("0x") == -1)
			return (-1);
		mod = 0;
		len += 2;
	}
	if (number >= 16)
	{
		value = ft_point(number / 16, mod);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (ft_putchar("0123456789abcdef"[number % 16]) == -1)
		return (-1);
	return (len + 1);
}
