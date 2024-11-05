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

char	*ft_strchr(const char *str, int l)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)l)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)l == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		l;
	size_t	s1_len;
	size_t	s2_len;
	i = 0;
	l = 0;
	if (!s1)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			res[l++] = s1[i++];
	}
	i = 0;
	while (s2[i])
		res[l++] = s2[i++];
	res[l] = '\0';
	return (res);
}

char	*ft_strrchr(const char *str, int l)
{
	int		i;
	char	*last;

	last = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)l)
			last = (char *)&str[i+1];
		i++;
	}
	return (last);
}

char	*get_to_line(char *readed)
{
	char	*res;
	int		i;

	if (!readed)
		return (NULL);
	i = 0;
	while (readed[i] != '\n' && readed[i])
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (readed[i] != '\n' && readed[i])
	{
		res[i] = readed[i];
		i++;
	}
	if (readed[i] == '\n')
	{
		res[i] = readed[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
