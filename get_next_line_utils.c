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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (new == NULL)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
		if (s1[i] == '\n')
		{
			new[i] = '\n';
			i++;
			break ;
		}
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	if (s1 == NULL)
		return (free(s1), ft_strdup(s2));
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (free(s1), NULL);
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i++] = s2[j++];
		if (s2[j] == '\n')
		{
			s3[i] = '\n';
			i++;
			break ;
		}
	}
	s3[i] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strcpy(char *dest, char *src, int start)
{
	int		i;
	char	temp_letter;

	i = 0;
	while (src[start] != '\0')
	{
		temp_letter = src[start];
		dest[i] = temp_letter;
		++i;
		++start;
	}
	dest[i] = '\0';
	return (dest);
}

void	clean_buff(char	buffer[BUFFER_SIZE + 1])
{
	char	temp[BUFFER_SIZE + 1];
	int		i;

	i = 0;
	while(buffer[i] != '\n' && buffer[i])
		i++;
	ft_strcpy(temp, buffer, i + 1);
	ft_strcpy(buffer, temp, 0);
}
