/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehakcan <mehakcan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:53:55 by mehakcan          #+#    #+#             */
/*   Updated: 2024/01/04 13:22:02 by mehakcan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	a;
	size_t	j;

	a = ft_strlen(dst);
	j = ft_strlen((char *)src);
	i = 0;
	if (dstsize <= a)
		return (dstsize + j);
	while (src[i] != '\0' && a + i + 1 < dstsize)
	{
		dst[a + i] = src[i];
		i++;
	}
	dst[a + i] = '\0';
	return (a + j);
}
