/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehakcan <mehakcan@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:16:11 by mehakcan          #+#    #+#             */
/*   Updated: 2024/06/04 15:32:34 by mehakcan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd, int i, int rd_byte)
{
	char	buffer;
	char	*line;

	line = (char *)malloc(sizeof(char) * 8888);
	buffer = 0;
	if (fd < 0 || !line)
		return (NULL);
	while (rd_byte > 0)
	{
		rd_byte = read(fd, &buffer, 1);
		if (rd_byte <= 0)
			break ;
		if (buffer == '\n')
		{
			line[i++] = buffer;
			break ;
		}
		if (i < 8887)
		{
			line[i] = buffer;
			i++;
		}
	}
	line[i] = '\0';
	return (line);
}
