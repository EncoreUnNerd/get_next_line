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


char	*reading(int fd, char	*readed)
{
	char	*buffer;
	int		rd_bytes;
	char	*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rd_bytes = 1;
	while (rd_bytes != 0 && !ft_strchr(readed, '\n'))
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (rd_bytes == 0)
			break ;
		buffer[rd_bytes] = '\0';
		temp = readed;
		readed = ft_strjoin(readed, buffer);
		free(temp);
		if (!readed)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (readed);
}
char	*get_next_line(int fd)
{
	char		*res;
	char		*new_readed;
	static char	*readed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	readed = reading(fd, readed);
	if (!readed)
		return (NULL);
	res = get_to_line(readed);
	if (!res)
		return (NULL);
	// Trouver la position du caractère '\n' dans readed
	char *newline_pos = ft_strchr(readed, '\n');
	if (newline_pos)
	{
		// Calculer la longueur de la partie restante après '\n'
		size_t remaining_length = ft_strlen(newline_pos + 1);
		// Allouer de la mémoire pour la nouvelle readed
		new_readed = malloc(sizeof(char) * (remaining_length + 1));
		if (!new_readed)
		{
			free(res);
			return (NULL);
		}
		// Copier la partie restante dans new_readed
		ft_strlcpy(new_readed, newline_pos + 1, remaining_length + 1);
		free(readed);
		readed = new_readed;
	}
	else
	{
		// Si pas de '\n', libérer readed et le mettre à NULL
		free(readed);
		readed = NULL;
	}
	return (res);
}

// int	main(void)
// {
// 	char	*te;
// 	int		fd;

// 	fd = open("exemple.txt", O_RDONLY);
// 	te = get_next_line(fd);
// 	while(te != NULL)
// 	{
// 		printf("%s", te);
// 		te = get_next_line(fd);
// 	}
// }
