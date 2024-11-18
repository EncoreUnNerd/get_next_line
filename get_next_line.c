/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:31:27 by mhenin            #+#    #+#             */
/*   Updated: 2024/10/31 11:31:29 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static t_buffer	buffer = {.cursor = 0};
	int				rd_bytes;
	char			*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = NULL;
	if (buffer.cursor != 0)
	{
		res = get_line_from_buffer(&buffer);
		if (buffer.cursor != 0)
			return (res);
	}
	rd_bytes = 1;
	while (rd_bytes > 0)
	{
		rd_bytes = read(fd, buffer.buffer, BUFFER_SIZE);
		if (rd_bytes < 0)
		{
			if (res != NULL)
				free(res);
			return (NULL);
		}
		buffer.buffer[rd_bytes] = '\0';
		res = ft_strjoin(res, &buffer);
		if (buffer.cursor != 0)
			break ;
	}
	if (res && res[0] != '\0')
		return (res);
	return (free(res), NULL);
}
// int main(void)
// {
// 	int fd = open("exemple.txt", O_RDONLY);
// 	char *line;

// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// }
