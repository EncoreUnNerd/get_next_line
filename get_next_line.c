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
	char		buffer[BUFFER_SIZE + 1];
	int			rd_bytes;
	char		*res;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	rd_bytes = 1;
	while (rd_bytes > 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes < 0)
		{
			free(stock);
			return (NULL);
		}
		buffer[rd_bytes] = '\0';
		stock = ft_strjoin(stock, buffer);
		if (ft_is_endline(stock))
			break ;
	}
	res = ft_get_line(stock);
	stock = clear(stock);
	return (res);
}

// int	main(void)
// {
// 	char	*te;
// 	int		fd;

// 	fd = open("exemple.txt", O_RDONLY);
// 	te = get_next_line(fd);
// 	while (te != NULL)
// 	{
// 		printf("%s", te);
// 		free(te);
// 		te = get_next_line(fd);
// 	}
// }
