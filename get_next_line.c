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
#include "fcntl.h"
#include "stdio.h"
#include <stdio.h>

int	ft_is_endline(const char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			rd_bytes;
	char		*res;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (buffer[0] != '\0')
		res = ft_strdup(buffer);
	rd_bytes = 1;
	while (rd_bytes > 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes < 0)
			return (NULL);
		buffer[rd_bytes] = '\0';
		res = ft_strjoin(res, buffer);
		if (rd_bytes == 0)
			return (free(res), NULL);
		if (ft_is_endline(buffer) || rd_bytes < BUFFER_SIZE)
		{
			clean_buff(buffer);
			break ;
		}
	}
	return (res);
}

int main(void)
{
	int fd = open("exemple.txt", O_RDONLY);
	char *te = get_next_line(fd);

	while (te != NULL)
	{
		printf("%s", te);
		free(te);
		te = get_next_line(fd);
	}
	return (0);
}
