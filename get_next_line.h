/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:32:09 by mhenin            #+#    #+#             */
/*   Updated: 2024/10/31 11:32:10 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE + 1];
	int		cursor;
}	t_buffer;

char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, const char *src, int decale);
char	*get_line_from_buff(t_buffer *buffer);
char	*ft_strdup(const char *src);
int		ft_strlen(const char *str);
int		check_if_endline(char *str);

#endif
