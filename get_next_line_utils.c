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

char	*ft_strdup(const char *src)
{
	char	*res;
	int		src_len;
	int		i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	res = malloc(src_len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strdup_till_return(char *src)
{
	char	*res;
	int		src_len;
	int		i;

	src_len = 0;
	while (src[src_len] != '\n')
		src_len++;
	res = malloc(src_len + 2);
	i = 0;
	while (i <= src_len)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_strlen(const char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*get_line_decale(char	**stock)
{
	int		i;
	char	*temp;
	char	*res;

	i = 0;
	while ((*stock)[i] != '\n' && (*stock)[i] != '\0')
		i++;
	if ((*stock)[i] == '\0')
	{
		res = ft_strdup((*stock));
		free((*stock));
		return (res);
	}
	else
	{
		res = ft_strdup_till_return((*stock));
		temp = ft_strdup((*stock) + ft_strlen(res));
		free((*stock));
		*stock = ft_strdup(temp);
		free(temp);
		return (res);
	}
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	if (s1 == NULL)
		return (ft_strdup(s2));
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
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (free(s1), s3);
}
