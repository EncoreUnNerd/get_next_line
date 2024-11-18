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

char	*optim(char *s1, t_buffer *buffer, int i)
{
	int		j;
	char	*res;

	j = ft_strlen(s1);
	res = malloc(ft_strlen(s1) + i + 2);
	if (!res)
		return (free(s1), NULL);
	res = ft_strcpy(res, s1, 0);
	free(s1);
	i = 0;
	while (buffer->buffer[i] != '\n')
		res[j++] = buffer->buffer[i++];
	res[j] = '\n';
	res[++j] = '\0';
	if (buffer->buffer[i + 1] == '\0')
		buffer->cursor = 0;
	else
		buffer->cursor = i + 1;
	return (res);
}

char	*ft_strjoin(char *s1, t_buffer *buffer)
{
	int		i;
	char	*res;

	if (!s1)
		return (get_line_from_buff(buffer));
	i = check_if_endline(buffer->buffer);
	if (i >= 0)
		res = optim(s1, buffer, i);
	else
	{
		res = malloc(ft_strlen(s1) + ft_strlen(buffer->buffer) + 1);
		if (!res)
			return (free(s1), NULL);
		res = ft_strcpy(res, s1, 0);
		res = ft_strcpy(res, buffer->buffer, ft_strlen(s1));
		free(s1);
		buffer->cursor = 0;
	}
	return (res);
}

char	*reading(char	*res, t_buffer *buffer, int fd)
{
	int	rd_bytes;

	rd_bytes = 1;
	while (rd_bytes > 0)
	{
		rd_bytes = read(fd, buffer->buffer, BUFFER_SIZE);
		if (rd_bytes < 0)
		{
			if (res != NULL)
				free(res);
			return (NULL);
		}
		buffer->buffer[rd_bytes] = '\0';
		res = ft_strjoin(res, buffer);
		if (check_if_endline(res) >= 0)
			break ;
	}
	if (res && res[0] == '\0')
		return (free(res), NULL);
	return (res);
}

char	*get_next_line(int fd)
{
	static t_buffer	buffer = {.cursor = 0};
	char			*res;

	res = NULL;
	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	if (buffer.cursor != 0)
	{
		res = get_line_from_buff(&buffer);
		if (buffer.cursor != 0)
			return (res);
	}
	return (reading(res, &buffer, fd));
}
