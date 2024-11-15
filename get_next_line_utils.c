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

char	*ft_strdup(char *src)
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
	while (i < src_len + 1)
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
	res = malloc(src_len + 1);
	i = 0;
	while (i < src_len + 1)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_strlen(char *src)
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

#include <stdio.h>
int main(void)
{
	char	*stock;
	char	*res;

	stock = ft_strdup("je test la\n test de fou\nencore");
	res = get_line_decale(&stock);
	printf("[%s]\n",res);
	free(res);
	printf("(%s)", stock);
	res = get_line_decale(&stock);
	printf("[%s]\n",res);
	free(res);
	printf("(%s)", stock);
	res = get_line_decale(&stock);
	printf("[%s]\n",res);
	free(res);
	printf("(%s)", stock);
	return (0);
}
