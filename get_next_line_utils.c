/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:32:21 by mhenin            #+#    #+#             */
/*   Updated: 2024/10/31 11:32:23 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_if_endline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line_from_buffer(t_buffer *buffer)
{
	char	*res;
	int		i;
	int		line_length;

	i = buffer->cursor;
	while (buffer->buffer[i] != '\n' && buffer->buffer[i] != '\0')
		i++;
	line_length = i - buffer->cursor;
	if (buffer->buffer[i] == '\n')
		line_length++;
	res = malloc(line_length + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < line_length)
	{
		res[i] = buffer->buffer[buffer->cursor + i];
		i++;
	}
	res[i] = '\0';
	if (buffer->buffer[buffer->cursor + line_length - 1] != '\n')
		buffer->cursor = 0;
	else
		buffer->cursor += line_length;
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char *str, t_buffer *buffer)
{
	char	*res;

	if (!str)
		return (get_line_from_buffer(buffer));
	res = malloc(ft_strlen(str) + ft_strlen(buffer->buffer) + 1);
	if (!res)
		return (NULL);
	ft_strcpy(res, str);
	ft_strcpy(res + ft_strlen(str), buffer->buffer);
	free(str);
	return (res);
}
