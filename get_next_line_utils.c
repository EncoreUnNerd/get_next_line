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
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strdup(const char *src)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_line_from_buff(t_buffer *buffer)
{
	char	*res;
	int		i;

	i = buffer->cursor;
	while (buffer->buffer[i] != '\n' && buffer->buffer[i] != '\0')
		i++;
	if (buffer->buffer[i] == '\n')
	{
		res = malloc((i + 2) - buffer->cursor);
		if (!res)
			return (NULL);
		i = 0;
		while (buffer->buffer[buffer->cursor] != '\n')
			res[i++] = buffer->buffer[buffer->cursor++];
		res[i] = '\n';
		res[++i] = '\0';
		if (buffer->buffer[++buffer->cursor] == '\0')
			buffer->cursor = 0;
		return (res);
	}
	res = ft_strdup(buffer->buffer + buffer->cursor);
	buffer->cursor = 0;
	return (res);
}

char	*ft_strcpy(char *dest, const char *src, int decale)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[decale + i] = src[i];
		i++;
	}
	dest[decale + i] = '\0';
	return (dest);
}
