/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehakcan <mehakcan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:17:29 by mehakcan          #+#    #+#             */
/*   Updated: 2024/01/25 12:17:29 by mehakcan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_int(int w);
int	ft_check(char str);
int	ft_putchar(char x);
int	ft_string(char *str);
int	ft_unsigned(unsigned int w);
int	ft_hex(unsigned int number, char format);
int	ft_point(unsigned long int number, int mod);
int	ft_printf(const char *format, ...);

#endif