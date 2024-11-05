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
#include <fcntl.h>
#include <stdio.h>

char	*reading(int fd, char	*readed)
{
	char	*buffer;
	int		rd_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rd_bytes = 1;
	while (rd_bytes != 0 && !ft_strchr(readed, '\n'))
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (rd_bytes == 0)
			break ;
		buffer[rd_bytes] = '\0';
		readed = ft_strjoin(readed, buffer);
	}
	free(buffer);
	return (readed);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*readed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	readed = reading(fd, readed);
	if (!readed)
		return (NULL);
	res = get_to_line(readed);
	readed = ft_strrchr(readed, '\n');
	if (!readed)
		free(readed);
	return (res);
}

int	main(void)
{
	char	*te;
	int		fd;

	fd = open("exemple.txt", O_RDONLY);
	te = get_next_line(fd);
	while(te != NULL)
	{
		printf("%s", te);
		te = get_next_line(fd);
	}
}
