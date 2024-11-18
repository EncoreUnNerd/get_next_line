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
#include <stdlib.h>

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
	return (0);
}

int ft_strlen(const char *str)
{
    int length = 0;

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
	int		j;

	i = buffer->cursor;
	while (buffer->buffer[i] != '\n' && buffer->buffer[i] != '\0')
		i++;
	if (buffer->buffer[i] == '\n')
	{
		res = malloc((i + 2) - buffer->cursor);
		i = 0;
		while (buffer->buffer[buffer->cursor] != '\n')
			res[i++] = buffer->buffer[buffer->cursor++];
		res[i] = '\n';
		res[++i] = '\0';
		if (buffer->buffer[++buffer->cursor] == '\0')
			buffer->cursor = 0;
		return (res);
	}
	else
	{
		res = ft_strdup(buffer->buffer + buffer->cursor);
		buffer->cursor = 0;
		return (res);
	}
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, t_buffer *buffer)
{
	int		i;
	int 	j;
	int		k;
	char	*res;

	if (!s1)
		return (get_line_from_buff(buffer));
	i = check_if_endline(buffer->buffer);
	j = 0;
	if (i > 0)
	{
		j = ft_strlen(s1);
		res = malloc(j + i + 2);
		res = ft_strcpy(res, s1);
		k = 0;
		while (buffer->buffer[k] != '\n')
			res[j++] = buffer->buffer[k++];
		res[j] = '\n';
		res[++j] = '\0';
		if (buffer->buffer[i + 1] == '\0')
			buffer->cursor = 0;
		else
			buffer->cursor = k + 1;
	}
	else
	{
		res = malloc(ft_strlen(s1) + ft_strlen(buffer->buffer) + 1);
		res = ft_strcpy(res, s1);
		res = ft_strcpy(res + ft_strlen(s1), buffer->buffer);
		buffer->cursor = 0;
	}
	return (res);
}

#include <stdio.h>

int main() {
    char s1[] = "Hello, ";
    t_buffer buffer;
    ft_strcpy(buffer.buffer, "world!\nThis is a test.");
    buffer.cursor = 0;

    char *result = ft_strjoin(s1, &buffer);
    printf("Result: %s", result);
    printf("Result: %d\n", buffer.cursor);
    printf("Result: %s", get_line_from_buff(&buffer));
    free(result);
    return 0;
}
