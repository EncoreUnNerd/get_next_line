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

char	*get_next_line(int fd)
{
	static struct stock	*stock;
	int					read_r;
	char				*buffer;
	char				*res;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!check_if_endline(buffer))
	{
		read_r = read(fd, buffer, BUFFER_SIZE);
		if (read_r == 0 || read_r == -1)
			break ;
		add_back(buffer, &stock);
	}
	free(buffer);
	res = get_line(stock);
	clean_to_endline(&stock);
	if (res[0] == '\0')
		return (NULL);
	return (res);
}

int	main(void)
{
	int		fd;
	char	*te;

	fd = open("exemple.txt", O_RDONLY);
	te = get_next_line(fd);
	while (te != NULL)
	{
		printf("%s", te);
		te = get_next_line(fd);
	}
	return (0);
}
